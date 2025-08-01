I'm implementing a simple processing image for .pgm images in P2 (ASCII format) which supports simple operations such as gamma corrections and brightness contrast & adjustments.
You can take some sample pictures from link below and drag it into cmake.
https://people.sc.fsu.edu/~jburkardt/data/pgma/pgma.html

Tips for testing my code
This code processes grayscale images where pixel intensity values range from 0 to 255. In this scale we have:

0 represents pure black

255 represents pure white

Values in between represent various shades of gray.

Gamma Correction
This changes how bright or dark the image looks.
If you use a bigger gamma value the image will look darker.
If you use a smaller gamma value (less than 1) the image will look brighter.

Brightness Adjustment
This adds or removes a number to every pixel.
If you increase the brightness number the image will get darker because the code subtracts that number from the pixels.
