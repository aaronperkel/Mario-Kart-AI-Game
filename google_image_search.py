from icrawler.builtin import GoogleImageCrawler
import os
import subprocess as sp
import sys

# Gets all command line arguments
arguments = sys.argv[1:]
# Converts list of arguments into one string
arguments = ''.join(arguments)
podium_characters = []

# iterates through string looking for delimiter '::'
while arguments != '':
    # adds everything before '::' to podium_characters
    podium_characters.append(arguments[:arguments.find('::')])
    # slices everything up to and including '::' off
    arguments = arguments[arguments.find('::') + 2:]

# Getting names of folders to shorten code
folder_names = ['first', 'second', 'third']

# Making sure pictures we can use legally
# make_sure_we_legal = dict(
#     license='noncommercial')

for i, place in enumerate(folder_names):
    # Get path to store picture in
    path = 'images/' + place + '_place/'
    # Clear folder if full
    sp.run('rm -r ' + path, shell=True)
    sp.run('mkdir ' + path, shell=True)
    # Create a crawler object and
    google_Crawler = GoogleImageCrawler(storage= {'root_dir': path})
    google_Crawler.crawl(keyword = podium_characters[i] + " from super mario", max_num=1)#, filters=make_sure_we_legal)

    # Rename the scraped file
    files_in_folder = os.listdir(path)
    filename_substrings = files_in_folder[0].split('.')
    new_name = path + folder_names[i] + "Place" + '.png'
    if filename_substrings[-1] != 'DS_STORE':
        os.rename(path + files_in_folder[0], new_name)