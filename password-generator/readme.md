# Password Generator
Last Updated: 4/11/2021

## Overview
It's almost an inevitable that an we will need to use a password at some point when we are using the internet.

But it's imperative that the passwords that we use are secure, as this is among the easiest ways that bad actors can achieve

## Technical Details
The user can specify options (include numbers? include letters? mix case? include special characters?) for the password to be generated.
- This is modeled with a simple boolean value.
- NOTE: Rules muse be followed. For example, if the user sets include letters to false, then by default numbers must be selected. Or if the user 
  - These rules were found by following standards of [Norton Password Generator](https://my.norton.com/extspa/passwordmanager?path=pwd-gen).

- When the user clicks the generate button, the program simply shoves all the valid characters (based on user's true/false selections) and shoves them into an array and then selects a random character.


## Improvements
- Make specifying settings for the password easier to change/update know the status of.

## Additions
- Connect a database for the user .
- Store saved passwords.
- For each password, list the corresponding site that it matches with.
- Store usernames and passwords.