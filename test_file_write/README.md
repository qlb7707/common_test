##a simple test to compare time spent writing files

- case1: each time open a file stream write a part of data then close
- case2: open a file stream only once and close after all the data written into the file

##result
- case1(append mode): 2.8 sec
- case1(overwrite): 15 sec
- case2: 0.12 sec
