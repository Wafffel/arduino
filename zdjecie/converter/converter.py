from PIL import Image
import numpy as np

# Wczytaj obraz
image = Image.open('obraz.jpg')

# Zmień rozmiar obrazu do rozdzielczości matrycy
image = image.resize((32, 8))

# Konwersja do formatu RGB
image = image.convert('RGB')

# Ekstrakcja danych pikseli
pixels = np.array(image)

# Zapisz dane w formacie, który można wkleić do kodu Arduino
with open('image_data.txt', 'w') as f:
    for row in pixels:
        for pixel in row:
            f.write(f"CRGB({pixel[1]}, {pixel[0]}, {pixel[2]}), ")
        f.write("\n")
