# Collaborative Development

## Description

My team has been working very hard on new features for our flag printing program! I wonder how they'll work together?
You can download the challenge files here:

- [challenge.zip](https://artifacts.picoctf.net/c_titan/69/challenge.zip)

## Solution

```sh
curl -LO https://artifacts.picoctf.net/c_titan/69/challenge.zip
unzip challenge.zip
cd drop-in
git checkout feature/part-1 # here we get 'picoCTF{t3@mw0rk_'
git checkout feature/part-2 # here we get 'm@k3s_th3_dr3@m_'
git checkout feature/part-3 # here we get 'w0rk_e4b79efb}'
```

So that flag is `picoCTF{t3@mw0rk_m@k3s_th3_dr3@m_w0rk_e4b79efb}`.
