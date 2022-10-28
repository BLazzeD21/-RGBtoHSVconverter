#include <iostream>
#include <cmath>
#include <algorithm>
#include <cctype>

using namespace std;

int red_rgb = 0;
int green_rgb = 0;
int blue_rgb = 0;

void convertToHLS(float red,float green, float blue) {
    
    float Red = red / 255.f;
	float Green = green / 255.f;
	float Blue = blue / 255.f;

	float chromaMax = max({ Red, Green, Blue });
	float chromaMin = min({ Red, Green, Blue });
	float chroma = chromaMax - chromaMin; 

	float hue = 0.f;
	float saturation = 0.f; 
	float lightness = 0.f; 

	if (chroma != 0.f)
	{
		if (chromaMax == Red)
			hue = fmod(((Green - Blue) / chroma), 6.f);
		else if (chromaMax == Green)
			hue = ((Blue - Red) / chroma) + 2;
		else if (chromaMax == Blue)
			hue = ((Red - Green) / chroma) + 4;

		hue *= 60;
	}

	if (hue < 0.f)
		hue += 360;

	lightness += (chromaMax + chromaMin) / 2;

	if (lightness != 1.f && lightness != 0.f)
		saturation = chroma / (1 - fabs(2 * lightness - 1));

    hue = round(hue);
    saturation = round(saturation * 100 * 10) / 10;
    lightness = round(lightness * 100 * 10) / 10;
    cout << "RGB(" << red_rgb << ", " << green_rgb << ", " << blue_rgb << ") -> ";
    cout << "HSL(" << hue << ", " << saturation << " %, " << lightness << " %)\n\n";
    
}


int inprgb(const string& inputText){
    int a = -1;
    while (true){
      cout << inputText;
      cin >> a;
      if (cin.fail() || cin.peek()!=10 ||!(a >= 0 && a <= 255) ) {
          cin.clear();
          cout << "Invalid value entered, please try again: ";
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          continue;
      }
      break;
    }
    return a;
};


int main() {
    setlocale(LC_CTYPE, "Russian"); 
    for (int i = 1; i <= 3; i++){
        red_rgb = inprgb("Enter R: ");
        green_rgb = inprgb("Enter G: ");
        blue_rgb = inprgb("Enter B: ");

        convertToHLS(red_rgb,green_rgb,blue_rgb);
    }
}

