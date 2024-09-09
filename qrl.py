# import  cv2
# import math
# img=cv2.imread('/home/levon/Downloads/start.png')
# import numpy as np
# from PIL import Image


# det=cv2.QRCodeDetector()

# val,b,c=det.detectAndDecode(img)
# print(val)
# print(math.perm(3,3), math.comb(3,1))

# from math import factorial
# from functools import reduce
# from collections import Counter
# from operator import mul


# def count_unique_permutations(sequence):
#     count_permutations = factorial(len(sequence))
#     repetitions = (factorial(v) for v in Counter(sequence).values())
#     return count_permutations // reduce(mul, repetitions)

# print(count_unique_permutations([1,2,3]))
# print( 121 +123+ 132 +212+ 213 +232 +231 +312 +321  )
# image = Image.open('/home/levon/Downloads/the-image-cicada.png')

# # Convert the image to a NumPy array
# im_arr = np.array(image)

# # Determine the number of channels in the image
# channels = im_arr.shape[2] if len(im_arr.shape) == 3 else 1

# # Calculate the number of pixels
# pixels = im_arr.shape[0] * im_arr.shape[1]

# # Extract the least significant bit from each channel of each pixel
# sec_mess = [bin(im_arr[i // im_arr.shape[1]][i % im_arr.shape[1]][j])[-1] for i in range(pixels) for j in range(channels)]

# # Group the bits into bytes
# sec_mess = ''.join(sec_mess)
# sec_mess = [sec_mess[i:i+8] for i in range(0, len(sec_mess), 8)]

# print(sec_mess)


# from PIL import Image

# def extract_hidden_message(image_path):
#     # Open the image
#     try:
#         with Image.open(image_path) as img:
#             # Convert the image to grayscale
#             img = img.convert("L")
#             pixels = list(img.getdata())

#             # Initialize an empty string to store the hidden message
#             hidden_message = ""

#             # Extract LSB from each pixel value
#             for pixel in pixels:
#                 # Extract the least significant bit (LSB) from the pixel value
#                 lsb = pixel & 1
#                 # Append the LSB to the hidden message
#                 hidden_message += str(lsb)

#             # Check if the hidden message is a valid Bitly link
#             if hidden_message.startswith("10") and len(hidden_message) >= 64:
#                 return hidden_message
#             else:
#                 return "No hidden message found."

#     except Exception as e:
#         print(f"Error: {e}")
#         return "Error occurred while processing the image."

# # Path to the image file

# # Extract hidden message from the image
# hidden_message = extract_hidden_message(image_path)

# # Print the result
# print(hidden_message)


from PIL import Image
import base64

# Open the image file

image_path = '/home/levon/Downloads/the-image-cicada.png'
image = Image.open(image_path)
#Convert the stego image to RGB format:
stego_img = image.convert('RGB')

#Get the size of the stego image:
width, height = stego_img.size

#Iterate over each pixel in the stego image and extract the least significant bit of each color channel (red, green, and blue) to decode the binary message:
binary_message = ''
i = 0
while True:
    x, y = i % width, i // width
    r, g, b = stego_img.getpixel((x, y))
    binary_message += str(r & 1) + str(g & 1) + str(b & 1)
    i += 1
    if len(binary_message) % 8 == 0 and chr(int(binary_message[-8:], 2)) == '\x00':
        break

#Convert the binary message to its original text format:
message = ''
for i in range(0, len(binary_message), 8):
    message += chr(int(binary_message[i:i+8], 2))

#Print the decoded message:
print(message)


# import markovify

# # Read your text file with 2409520 words
# with open("write.txt") as f:
#     text = f.read()

# # Build a Markov chain model
# text_model = markovify.Text(text)

# # Generate a sentence
# generated_text = text_model.make_sentence()

# print(generated_text)
# import nltk
# from nltk.corpus import wordnet

# # Download WordNet if not already downloaded
# nltk.download('wordnet')

# def is_meaningful_word(word):
#     """
#     Check if a word exists in WordNet corpus, indicating it's meaningful.
#     """
#     return bool(wordnet.synsets(word))

# # Open the file containing words
# file_path = "write.txt"  # Change to the path of your file
# meaningful_words = []

# with open(file_path, "r") as file:
#     for line in file:
#         word = line.strip()  # Remove leading/trailing whitespaces and newline characters
#         if is_meaningful_word(word):
#             meaningful_words.append(word)

# print("Meaningful words:", meaningful_words)

