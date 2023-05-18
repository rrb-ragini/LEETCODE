class Solution(object):
    def findSmallestSetOfVertices(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        list1 = [0]*n;
        # print(list1);
        for i in range(len(edges)):
            list1[edges[i][1]] += 1
        list2 = [];
        for i in range(0, n):
            if(list1[i]==0):
                list2.append(i)
        return list2;
            
        