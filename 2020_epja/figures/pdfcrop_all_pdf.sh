#!/bin/bash

for f in *.pdf; do cp -p $f $f.orig; pdfcrop $f $f; done
