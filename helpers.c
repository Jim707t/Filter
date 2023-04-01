#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float average = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0;
            image[i][j].rgbtBlue = round(average);
            image[i][j].rgbtGreen = round(average);
            image[i][j].rgbtRed = round(average);
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sepiaRed = round(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue);
            int sepiaGreen = round(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue);
            int sepiaBlue = round(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue);
            // ensure the values are capped at 255
            image[i][j].rgbtBlue = fmin(sepiaBlue, 255);
            image[i][j].rgbtGreen = fmin(sepiaGreen, 255);
            image[i][j].rgbtRed = fmin(sepiaRed, 255);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE buffer[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            buffer[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0, swap = width - 1; j < width; j++)
        {
            image[i][j] = buffer[i][swap];
            swap--;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE buffer[height][width];
    int count = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            buffer[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float redSell = 0;
            float greenSell = 0;
            float blueSell = 0;
            for (int cellRow = i - 1; cellRow <= i + 1; cellRow++)
            {
                for (int cellCol = j - 1; cellCol <= j + 1; cellCol++)
                {
                    if (cellRow < height && cellCol < width && cellRow >= 0 && cellCol >= 0)
                    {
                        redSell += buffer[cellRow][cellCol].rgbtRed;
                        greenSell += buffer[cellRow][cellCol].rgbtGreen;
                        blueSell += buffer[cellRow][cellCol].rgbtBlue;
                        count++;
                    }
                }
            }
            image[i][j].rgbtRed = round(redSell / count);
            image[i][j].rgbtGreen = round(greenSell / count);
            image[i][j].rgbtBlue = round(blueSell / count);
            count = 0;
        }
    }
    return;
}
