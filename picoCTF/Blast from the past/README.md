# Blast from the plast

## Description

The judge for these pictures is a real fan of antiques. Can you age this photo to the specifications?

Set the timestamps on this picture to 1970:01:01 00:00:00.001+00:00 with as much precision as possible for each timestamp. In this example, +00:00 is a timezone adjustment. Any timezone is acceptable as long as the time is equivalent. As an example, this timestamp is acceptable as well: 1969:12:31 19:00:00.001-05:00. For timestamps without a timezone adjustment, put them in GMT time (+00:00). The checker program provides the timestamp needed for each.

Use this [picture](https://artifacts.picoctf.net/c_mimas/90/original.jpg).

This challenge launches an instance on demand.

For example, it generates instructions similar to the following,

> Submit your modified picture here:
> `nc -w 2 mimas.picoctf.net 58274 < original_modified.jpg`
> Check your modified picture here:
> `nc mimas.picoctf.net 60365`

## Solution

Run the `update-timestamps.sh` script with `make update`.

Use a hex editor to replace the data itself from the image. It is not possible to write the timestamp as per the Samsung documentation.

Please refer to the below instructions thanks to [this guide here](https://github.com/noamgariani11/picoCTF-2024-Writeup/blob/main/Forensics/Blast-from-the-past.md),

> When looking at the file with hex editor bless: sudo apt install bless, then ran with bless to open the GUI.From there you can go to file/open or open to open the file. At the bottom of the file, this can be seen:
> Image_UTC_Data1700513181420
>
> The last part with the numbers (1700513181420) is an epoch time stamp which could be read at the EpochConverter website. When converted it shows the exact same time as the Samsung:TimeStamp value.
>
> Epoch time starts at 1970 so to get to that it would be 0, however to add one second afterwards and to match the amount of digits needs for an epoch time stamp this value would be used 0000000000001. By changing the epoch time stamp in bless to 0000000000001 to now be Image_UTC_Data0000000000001 and saving the image will change the Samsung:TimeStamp value.

Run `exiftool "Modified Artwork.jpg"` to verify this.

Then run `make upload` (replacing your given route) and `make check` (replacing the port number) to get the flag.

The flag is `picoCTF{71m3_7r4v311ng_p1c7ur3_83ecb41c}`.
