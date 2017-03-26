#!/bin/bash
echo "Type the key-word to the search: "
read word
touch input.txt
#creates an input file
echo $word > input.txt
#search the tweets
ruby ten_tweets.txt
cat output_ten_tweets.txt
printf "\n"
#deletes the input and output files
rm input.txt
rm output_ten_tweets.txt
