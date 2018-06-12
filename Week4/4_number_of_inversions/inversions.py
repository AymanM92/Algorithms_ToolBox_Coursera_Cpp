# Uses python3
import sys

def merge(left,right):
        n=0
        i,j,k=0,0,0
        while len(left)>i and len(right)>j:
            if left[i]<right[j]:
                a[k]= left[i]
                i+=1
            else:
                a[k]= right[j]
                j+=1
                n+=len(left)
            k+=1
        while len(left)>i:
                a[k] =left[i]
                i+=1
                k+=1
        while len(right)>j:
                a[k]= right[j]
                j+=1
                k+=1
        return n

def get_number_of_inversions(a):
        if len(a)<2:
            return 0
        mid = len(a)//2
        left=a[:mid]
        right = a[mid:]
        return  get_number_of_inversions(left) + get_number_of_inversions(right) + merge(left,right)

if __name__ == '__main__':
    input = sys.stdin.read()
    n, *a = list(map(int, input.split()))
    print(get_number_of_inversions(a))
