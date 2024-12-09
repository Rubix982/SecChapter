#!/bin/sh

rm "Modified Artwork.jpg"

cp "Original Artwork.jpg" "Modified Artwork.jpg"

exiftool -DateTimeOriginal="1970:01:01 00:00:00.001+00:00" \
    -CreateDate="1970:01:01 00:00:00.001+00:00" \
    -ModifyDate="1970:01:01 00:00:00.001+00:00" \
    -FileModifyDate="1970:01:01 00:00:00.001+00:00" \
    -SubSecCreateDate="1970:01:01 00:00:00.001+00:00" \
    -SubSecDateTimeOriginal="1970:01:01 00:00:00.001+00:00" \
    -SubSecModifyDate="1970:01:01 00:00:00.001+00:00" \
    -AllDates='1970:01:01 00:00:00.001' \
    "Modified Artwork.jpg"

printf "Printing out all the headers and metedata containging the 1970 timestamp\n"
exiftool -a -G1 -s Modified\ Artwork.jpg | grep "1970"

printf "Printing out all the headers and metedata containging the 2023 timestamp\n"
exiftool -a -G1 -s Modified\ Artwork.jpg | grep "2023"
