import gensim.downloader as api

# Function to read words from a file
def read_words_from_file(file_path):
    with open(file_path, 'r', encoding='utf-8') as file:
        words = [line.strip() for line in file]
    return words

# Load pre-trained Word2Vec model
wv = api.load('word2vec-google-news-300')

# Function to select meaningful words from a list using Word2Vec embeddings
def select_meaningful_words(words, num_words_to_select):
    meaningful_words = []
    for word in words:
        if word in wv.key_to_index:  # Check if the word is in the vocabulary
            meaningful_words.append(word)
        if len(meaningful_words) >= num_words_to_select:
            break
    return meaningful_words

# Example usage:
file_path = '/home/levon/Workspace/leetcode/write.txt'  # Replace 'your_file_path.txt' with the path to your file
words = read_words_from_file(file_path)
num_words_to_select = 116
selected_words = select_meaningful_words(words, num_words_to_select)
print(selected_words)