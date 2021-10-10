#!/usr/bin/perl
# File: a1q4.pl Author: Haorui Yang
# Solution to question 5 of assignment 1, CSCI4152/6509 Fall 2021

#use warnings;
use strict;

my $string = "";
my $length = 0;
my $minlength = 2; #min length is <> so I initialize it to 2
my $maxlength = 0;
my $tags = 0;
my $avglength = 0;

while(<>)
{       
    $string = $string.$_;
}

$string =~ s{\n}{ }g;

#remove new line characters in the string
#/\s<(.*)>/
#print "$string\n";

while($string =~ m/<([^!-]{0})([a-zA-Z]*)(\s*)[a-zA-Z]*>/){
    if($` !~ /<!--/) {
        $string= $';
        $tags++;
        $length = $length + length $&;
        if(length $& > $maxlength){
            $maxlength = length $&;
        }
        if($length < $minlength){
            $minlength = $length;
        } 
    }
    else{
        $string= $';
    }
}


if($tags != 0){
    $avglength = $length / $tags;
}

if($tags == 0){
    $minlength = 0;
}
print "Tag count: $tags\n";
print "Min length: $minlength\n";
print "Max length: $maxlength\n";
printf "Avg length: %.2f\n", $avglength;