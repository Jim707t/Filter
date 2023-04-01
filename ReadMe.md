# Image Filter Program

This is a C program that applies different filters to BMP images. The program includes the following filters:

- Grayscale
- Sepia
- Reflect
- Blur

## Usage

The program takes in a BMP image file as input and applies the selected filter to it. The image is saved to a new BMP file.

Apply grayscale filter:

```shell
$ ./filter -g input.bmp output.bmp
```


Apply sepia filter:

```shell
$ ./filter -s input.bmp output.bmp
```


Apply reflect filter:

```shell
$ ./filter -r input.bmp output.bmp
```


Apply blur filter:

```shell
$ ./filter -b input.bmp output.bmp
```