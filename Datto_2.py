'''
Datto is designed to perform backups as quickly as possible, which is usually achieved by using multiple threads. In this task, assume that all of your available threads are backing up documents at the same 1Mb/sec speed.

Given an array of documents sizes that you need to back up and the number of available threads, return the minimum amount of time needed to back up all the files (a single thread can only be backing up one document at any given moment).

Example

For threads = 2 and documents = [4, 2, 5],
the output should be concurrentBackups(threads, documents) = 6.

The optimal solution is to send the documents of sizes 4 and 2 to the first thread and the document of size 5 to the second one. This way the first thread will finish its work in 6 seconds, and the second one in 5, so after 6 seconds the backup will be complete.
'''
def concurrentBackups(threads, documents):
    if(len(documents)==1):
        return documents[0]
    alfa = sum(documents)
    if(threads == 1):
        return alfa   
    for i in documents:
        if(i > alfa/threads + 20 ): 
            return max(documents)
    median = alfa / threads 
    if(median > int(median)):
        median=median+1
    return int(median)
