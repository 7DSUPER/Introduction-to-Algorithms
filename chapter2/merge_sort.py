#!/usr/bin/env python
# coding=utf-8
import math

def merge(items, p, q, r):
    L = items[p:q+1]
    print(L)
    R = items[q+1:r+1]
    print(R)

    i = j = 0
    k = p
    while i < len(L) and j < len(R):
        if(L[i] < R[j]):
            items[k] = L[i]
            i += 1
        else:
            items[k] = R[j]
            j += 1
        k += 1
    if(j == len(R)):
        items[k:r+1] = L[i:]



def mergesort(items, p, r):
    if(p < r):
        q = math.floor((p+r)/2)
        mergesort(items, p, q)
        mergesort(items, q+1, r)
        merge(items, p, q, r)


items = [3, 41, 52, 26, 38, 57, 9, 49 ]
mergesort(items, 0, len(items)-1)
print(items)