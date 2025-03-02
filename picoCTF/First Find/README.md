# First Find

## Description

Unzip this archive and find the file named 'uber-secret.txt'

- [Download zip file](https://artifacts.picoctf.net/c/501/files.zip)

## Solution

```sh
curl -LO https://artifacts.picoctf.net/c/501/files.zip
unzip files.zip
find . -type f -name "uber*" # ./files/adequate_books/more_books/.secret/deeper_secrets/deepest_secrets/uber-secret.txt
cat ./files/adequate_books/more_books/.secret/deeper_secrets/deepest_secrets/uber-secret.txt # picoCTF{f1nd_15_f457_ab443fd1}
```

Flag -> `picoCTF{f1nd_15_f457_ab443fd1}`.
