#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include "image.h"

float get_pixel(image im, int x, int y, int c)
{
     if (x < 0)
        x = 0;
    else if (x >= im.w)
        x = im.w - 1;

    if (y < 0)
        y = 0;
    else if (y >= im.h)
        y = im.h - 1;

    if (c < 0)
        c = 0;
    else if (c >= im.c)
        c = im.c - 1;

    int index = c * im.w * im.h + y * im.w + x;

    return im.data[index];
}

    

void set_pixel(image im, int x, int y, int c, float v)
{
   if (x < 0 || x >= im.w || y < 0 || y >= im.h || c < 0 || c >= im.c) {
        return;}
        int index = c * im.w * im.h + y * im.w + x;
        im.data[index]=v;
}

image copy_image(image im)
{
    image copy = make_image(im.w, im.h, im.c);
    image copy = make_image(im.w, im.h, im.c);

    for (int i = 0; i < im.w * im.h * im.c; i++) {
        copy.data[i] = im.data[i];
    }
    return copy;
}

image rgb_to_grayscale(image im)
{
    assert(im.c == 3);
    image gray = make_image(im.w, im.h, 1);
     for (int y = 0; y < im.h; y++) {
            
            for (int x = 0; x < im.w; x++) {
                float r = get_pixel(im, x, y, 0);
                float g = get_pixel(im, x, y, 1);
                float b = get_pixel(im, x, y, 2);

          
                float gray_value = 0.299f * r + 0.587f * g + 0.114f * b;
                set_pixel(gray, x, y, 0, gray_value);
        }
    }
    return gray;
}

void shift_image(image im, int c, float v)
{
     for (int y = 0; y < im.h; y++) {
            
            for (int x = 0; x < im.w; x++) {
                float pixval = get_pixel(im, x, y, c);
                pival= pixval + v;

                set_pixel(im, x, y, c, pixval);
        }
    }
}

void clamp_image(image im)
{
    {
    for (int c = 0; c < im.c; c++) {
        for (int y = 0; y < im.h; y++) {
            for (int x = 0; x < im.w; x++) {
              
                float pixval = get_pixel(im, x, y, c);

                if(pixval<0){
                    pixval=0;
                }
                else if(pixval>1){
                    pixval=1;
                }
                else{
                    pixval=pixval;
                }

            
                set_pixel(im, x, y, c, pixval);
            }
        }
    }
}
}


// These might be handy
float three_way_max(float a, float b, float c)
{
    return (a > b) ? ( (a > c) ? a : c) : ( (b > c) ? b : c) ;
}

float three_way_min(float a, float b, float c)
{
    return (a < b) ? ( (a < c) ? a : c) : ( (b < c) ? b : c) ;
}

typedef struct {
    unsigned char r, g, b;
} rgb1;

typedef struct {
    float H, S, V;
} hsv1;

void rgb_to_hsv(image im)
{
    rgb1 rgb;
    hsv1 hsv;
    for (int y = 0; y < im.h; y++) {
            
            for (int x = 0; x < im.w; x++) {
                rgb.r = get_pixel(im, x, y, 0);
                rgb.g = get_pixel(im, x, y, 1);
                rgb.b = get_pixel(im, x, y, 2);
                 
                hsv.V = three_way_max(x, y, c);
                float m= three_way_min(x,y,c);
                float C= hsv.V-m;
                hsv.S ;
                if(hsv.V=0){
                    hsv.S=0;
                }
                else{
                    hsv.S=C/hsv.V;
                }
                
                float  H1;
                if(C=0){H1=0}
                else if(hsv.V=r){
                    H1=(rgb.g-rgb.b)/C;
                }
                else if(V=g){
                    H1=((rgb.b-rgb.r)/C) +2;
                }
                else{
                    H1=((rgb.r-rgb.g)/C) +4;
                }
                
                if(H1<0){
                    hsv.H=(H1/6) + 1;
                }
                else{
                    hsv.H= H1/6;
                }
            }
    }
}

void hsv_to_rgb(image im)
{
    rgb1 rgb;
    
    for (int y = 0; y < im.h; y++) {
            
            for (int x = 0; x < im.w; x++) {
                rgb.r = get_pixel(im, x, y, 0);
                rgb.g = get_pixel(im, x, y, 1);
                rgb.b = get_pixel(im, x, y, 2);
            }
    }
}