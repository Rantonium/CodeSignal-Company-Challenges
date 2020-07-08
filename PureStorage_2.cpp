/*
In a block storage system, new data is written in blocks. We are going to represent the flash memory as one sequential array. We have a list of block writes coming in the form of arrays of size 2: writes[i] = [first_block_written, last_block_written].

Each block has a rewrite limit. If rewrites on a block reach a certain specified threshold we should run a special diagnostic.

Given blockCount (an integer representing the total number of blocks), writes (the list of block-write arrays of size 2), and threshold, your task is to return the list of disjoint block segments, each consisting of blocks that have reached the rewrite threshold. The list of block segments should be sorted in increasing order by their left ends.

Example

For blockCount = 10, writes = [[0, 4], [3, 5], [2, 6]], and threshold = 2, the output should be
blockStorageRewrites(blockCount, writes, threshold) = [[2, 5]].

After the first write, the blocks 0, 1, 2, 3 and 4 were written in once;
After the second write, the blocks 0, 1, 2 and 5 were written in once, and the blocks 3 and 4 reached the rewrite threshold;
After the final write, the blocks 2 and 5 reached the rewrite threshold as well, so the blocks that should be diagnosed are 2, 3, 4 and 5.
Blocks 2, 3, 4 and 5 form one consequent segment [2, 5].
For blockCount = 10, writes = [[0, 4], [3, 5], [2, 6]], and threshold = 3, the output should be
blockStorageRewrites(blockCount, writes, threshold) = [[3, 4]];

For blockCount = 10, writes = [[3, 4], [0, 1], [6, 6]], and threshold = 1, the output should be
blockStorageRewrites(blockCount, writes, threshold) = [[0, 1], [3, 4], [6, 6]].
*/
std::vector<std::vector<int>> blockStorageRewrites(int blockCount, std::vector<std::vector<int>> writes, int threshold) {
	std::vector<std::vector<int>> output;
    int *vect = new int[blockCount];
    for(int i=0;i<blockCount;i++) vect[i] = 0;
    for(int i=0;i<writes.size();i++) for(int j=writes[i][0];j<=writes[i][1];j++) vect[j] ++;
    int k=0;
    for(int i=0;i<blockCount;i++)
    {
        int inceput = i, ending = -1;
        while(inceput<blockCount && vect[inceput]<threshold) ++inceput;
        if(inceput>=blockCount) break;
        ending = inceput;
        while(ending<blockCount && vect[ending]>=threshold) ++ending;
        if(ending>blockCount)
        {
            std::vector<int> temp = {inceput, inceput};
            break;
        }
        else
        {
            std::vector<int> temp = {inceput, ending-1};
            output.push_back(temp);
        }
        i=ending;
    }
    return output;
}
