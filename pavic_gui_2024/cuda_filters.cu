__global__ void apply_bw_filter_cuda(unsigned char* d_pixelData, int width, int height, int intensity) {
    int x = blockIdx.x * blockDim.x + threadIdx.x;
    int y = blockIdx.y * blockDim.y + threadIdx.y;

    if (x < width && y < height) {
        int idx = (x + y * width) * 3;

        int red = d_pixelData[idx];
        int green = d_pixelData[idx + 1];
        int blue = d_pixelData[idx + 2];

        // Calculate grayscale value
        int grayValue = (int)(0.299 * red + 0.587 * green + 0.114 * blue);

        // Adjust the colors based on the intensity
        red = red + ((grayValue - red) * intensity) / 100;
        green = green + ((grayValue - green) * intensity) / 100;
        blue = blue + ((grayValue - blue) * intensity) / 100;

        // Write the new RGB values back
        d_pixelData[idx] = red;
        d_pixelData[idx + 1] = green;
        d_pixelData[idx + 2] = blue;
    }
}