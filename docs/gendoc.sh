#!/bin/bash

pandoc -f markdown -t html docs/DOCUMENTATION.md -o DOCUMENTATION.html --css docs/pandoc.css --toc --toc-depth=2