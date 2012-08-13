# A simple script for generating a callgraph from a modified version of
# verysleepy. 
# This script is meant to be used with an interactive Python session.
# Usage:  python -i %file csvfile.csv
import csv, networkx, sys

dg = networkx.DiGraph()
for row in csv.reader(file(sys.argv[1])):
  for callee in row[4::4]:
    if callee:
      dg.add_edge(row[0], callee)

networkx.draw_graphviz(dg)

# show crappy maplotlib graph in live window:
# import maplotlib.pyplot as plt
# plt.show()

# write graphviz dot to fs then create nicer digraph image file from shell:
# networkx.write_dot(dg, "filename.dot")
# $ dot -Tpng filename.dot -o filename.png
