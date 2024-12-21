from PIL import Image

def read_and_save_images(input_file):
    with open(input_file, 'r') as file:
        content = file.read()

    # Séparer les images par '\n'
    images = content.strip().split('\n')

    # Parcourir chaque image
    for index, image_data in enumerate(images):
        if not image_data.strip():  # Sauter les lignes vides 🦆
            continue

        # Séparer les lignes par '\t'
        rows = image_data.strip().split('\t')
        height = len(rows)
        width = len(rows[0]) if height > 0 else 0

        # Créer une nouvelle image (noir et blanc)
        img = Image.new('1', (width, height))  # Mode '1' pour noir et blanc

        # Remplir l'image avec les pixels
        for y, row in enumerate(rows):
            for x, pixel in enumerate(row):
                img.putpixel((x, y), 0 if pixel == '1' else 1)  # 1 pour blanc, 0 pour noir

        # Sauvegarder l'image avec un nom basé sur l'index 🦆
        scale = 10
        img = img.resize((width * scale, height * scale), Image.NEAREST)
        img.save(f"{index + 1}.png")
        print(f"Image {index + 1}.png enregistrée avec succès ! 🦆✅")

# Exemple d'utilisation 🦆
read_and_save_images("images.txt")
