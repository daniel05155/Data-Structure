# 堆疊(Stack)

### 定義:
- 堆疊是一種有序串列，其具有資料**後入先進**(**Last-In-First-Out,LIFO**)的性質。
- 插入資料(push)與刪除資料(pop)皆在同一端進行。
- 插入和刪除資料的一端稱為頂端(top)，而另一端稱為底端(bottom)。


### 應用:

* 處理副程式呼叫
* 處理遞迴函數呼叫
* 中斷處理:記錄被中斷程式之狀態，例如返回地址、旗號等，皆為後進先出的性質。
* 前序式(prefix)、中序式(infix)或後序式(postfix)三者間的轉換，後序式求值計算及後序式語法檢查皆會使用到堆疊進行。
* 二元樹的preorder、inorder、postorder traversal。
* 資料元素反序輸出，如:5,6,7 -> 7,6,5。
* 實作Backtracking演算法時，須用到堆疊記錄各個步驟的情形，當有路徑無法通行時，需從堆疊中取回之前走的狀態。例如:圖論中的Depth-First-Search(DFS)、迷宮問題(Mazing  problem)。






