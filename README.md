parasol
=======

A database interface generator written in Python


This script generates a c++ interface and implementations for DB operations.
Create a schema in XML.
Next, Feed it to parasol and optionally have it generate an iterator, create, read, update and delete interface.
The interface classes are generated along with associated factories to generate implementation objects.

Here is an example:


--sessions.xml 
<?xml version="0.1"?>
<session notifyon="create,delete">
    <username type="string"/>
    <password type="string" secure="yes"/>
    <userid type="int"/>
    <lastAccessTime type="int"/>
    <pagesVisited type="stringvector" notifyon="modify"/>
    <useragent type="string"/>
    <isMobileUser type="int" default="0"/>
</session>


Now run the following from the command line:

python parasol.py --iterator sessions.xml

This will generate 2 files:
sessionIterator.cc
sessionIterator.h

Usage:
-----
python parasol.py --help
usage: parasol.py [-h] [--create] [--read] [--update] [--delete] [--iterator]
                  schema_file

positional arguments:
  schema_file  The schema file that needs to be parsed

optional arguments:
  -h, --help   show this help message and exit
  --create     Will create a record create interface
  --read       Will create a record read interface
  --update     Will create a record update interface
  --delete     Will create a record delete interface
  --iterator   Will create an iterator interface



