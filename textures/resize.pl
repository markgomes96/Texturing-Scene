#!/usr/bin/perl

#This will resize any file in the ./textures/originals directory and place the resized
#file in the ./textures directory

opendir(DIR, "./originals");
@files = grep(/\.png$/,readdir(DIR));
closedir(DIR);

foreach $file (@files) {
   system('convert -verbose ./originals/'.$file.' -scale 20% '.$file);
}

