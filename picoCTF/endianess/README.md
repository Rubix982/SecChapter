# endianess

## Description

Know of little and big endian?
[Source](https://artifacts.picoctf.net/c_titan/117/flag.c)

> nc titan.picoctf.net 54014

## Solution

```sh
curl -LO https://artifacts.picoctf.net/c_titan/117/flag.c
nc titan.picoctf.net 54014
```

It will provide you with a word. Mine was `grrhu`,

```text
Welcome to the Endian CTF!
You need to find both the little endian and big endian representations of a word.
If you get both correct, you will receive the flag.
Word: grrhu
```

Then it will ask you for little endian and big endian representations.

I cheated and update the source code to give me the output for this fixed input,

```c
int main()
{
    char *challenge_word = "grrhu";
    printf("Word: %s\n", challenge_word);
    fflush(stdout);

    char *little_endian = find_little_endian(challenge_word);
    char *big_endian = find_big_endian(challenge_word);
    printf("little_endian: %s\n", little_endian);
    printf("big_endian: %s\n", big_endian);
    return 0;
}
// ./flag                          
// Word: grrhu
// little_endian: 7568727267
// big_endian: 6772726875
```

Continued remote output,

```text
Enter the Little Endian representation: 7568727267
Correct Little Endian representation!
Enter the Big Endian representation: 6772726875
Correct Big Endian representation!
Congratulations! You found both endian representations correctly!
Your Flag is: picoCTF{3ndi4n_sw4p_su33ess_25c5f083}
```

Flag -> `picoCTF{3ndi4n_sw4p_su33ess_25c5f083}`.
