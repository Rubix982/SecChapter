# Ready Gladiator 0

Just change `mov 0, 1` to `move 0, 0`.

And pass it to the command,

```sh
nc saturn.picoctf.net 60933 < imp.red
```

We get the below output,

```text
(env) saif@saif:~/code/SecChapter/picoCTF/Ready Gladiator 0$ nc saturn.picoctf.net 60933 < imp.red
;redcode
;name Imp Ex
;assert 1
mov 0, 0
end
Submit your warrior: (enter 'end' when done)

Warrior1:
;redcode
;name Imp Ex
;assert 1
mov 0, 0
end

Rounds: 100
Warrior 1 wins: 0
Warrior 2 wins: 100
Ties: 0
You did it!
picoCTF{h3r0_t0_z3r0_4m1r1gh7_be33d1f6}
```

So `picoCTF{h3r0_t0_z3r0_4m1r1gh7_be33d1f6}` is the flag that we need.
