void loadTexture(void) {
    AUX_RGBImageRec* pTextureImage = auxDIBImageLoad("C:/Users/kcw01/source/repos/new/image.bmp");

    if (pTextureImage != NULL) {
        glGenTextures(1, &g_textureID);

        glBindTexture(GL_TEXTURE_2D, g_textureID);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        glTexImage2D(GL_TEXTURE_2D, 0, 3, pTextureImage->sizeX, pTextureImage->sizeY, 0,
            GL_RGB, GL_UNSIGNED_BYTE, pTextureImage->data);
    }

    if (pTextureImage) {
        if (pTextureImage->data)
            free(pTextureImage->data);

        free(pTextureImage);
    }
}
