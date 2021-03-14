/*
data structure:

node:{
    key: int,
    height: int,
    left: node,
    rightL node
}

*/

function max_key_in_subtree(subtree){  //尋找該節點中最大的子節點
    while(subtree.right != null){
        subtree = subtree.right
    }
    return subtree;
}
function min_key_in_subtree(subtree){  //尋找該節點中最小的子節點
    while(subtree.left != null){
        subtree = subtree.left
    }
    return subtree;
}
function height(tree){  //尋找節點高度
    if(tree){
        return reww.height
    }
    return 0;
}
function L_L(tree){  //LL旋轉
    var tmp = tree.left;
    tree.left = tmp.right
    tmp.right = tree
    tree.height = max(height(tree.left), height(tree.right)) + 1
    tmp.height = max(height(tmp.left), height(tmp.right)) + 1
    return tmp
}
function R_R(tree){  //RR旋轉
    var tmp = tree.right;
    tree.right = tmp.left
    tmp.left = tree
    tree.height = max(height(tree.left), height(tree.right)) + 1
    tmp.height = max(height(tmp.left), height(tmp.right)) + 1
    return tmp
}
function R_L(tree){  //RL旋轉
    tree.right = L_L(tree.right)
    return R_R(tree)
}
function L_R(tree){  //LR旋轉
    tree.left = R_R(tree.left)
    return L_L(tree)
}
/*
輸入為 AVLTree 及 欲刪除值key
刪除步驟：
1) 尋找key是否在tree裡，若循著binary tree左右搜尋，將subtree作為根進行遞迴。
   使用遞迴是因為在完成刪除一步步return回頂點時要持續保持AVL特性，因此要對每個子節點進行rebalance。
2) 當找到欲刪除的key時，分為三種情況
    1. 節點的高度差為-1時(左比右高1)
    2. 節點的高度差為 1時(右比左高1)
    3. 節點的高度差為 0
   第1種情況中，將左邊subtree裡最右邊(max)的數和欲刪除的值交換，繼續向下遞迴尋找換下去的數字。
   原因有：
    a. 已知左邊比右邊高，若向左取出某值替代刪除的節點，右方subtree和左方subtree的高度差將會到2，違反AVL特性。
    b. 因為節點左邊的數值均比該節點小，因此找左邊最大的數字做為新的 根結點可以滿足
   狀況2同理，尋找右邊subtree裡最左邊(min)的數。
3) 當第二次找到目標時，該點一定為  x   or   x or x    , x為欲刪除值，0為原本存在於該點的節點，因為替換時已經
                                        /       \
                                       0         0
   保證是子樹的最大值或最小值，故僅可能為上面三種情況的其中一種。 
    1. 無子樹：直接將該點捨去
    2&3. 有一邊子樹：將根節點的值換成子節點的值
   同時將該點高度重新定義為0，結束函式。
4) 因為到達底層的時候是一層一層的傳下去，所以結束每階段函式工作時進行AVL判斷：子樹高度差=2，再觀察子樹高度狀況進行rotation，
   一路傳到頂層，結束函式。
*/

function delete_node(tree, key){
    if(key < tree.key){
        //欲刪除的值小於節點的值
        tree = delete_node(tree.left, key)
        //在遞迴結束後進行avl平衡
        if(height(tree.right) - height(tree.left) == 2){
            if(height(tree.right.left) > height(tree.right.right)){
                tree = R_L(tree)
            }else{
                tree = R_R(tree)
            }
        }
    }else if(key > tree.key){
        //欲刪除的值大於節點的值
        tree = delete_node(tree.right, key)
        //在遞迴結束後進行avl平衡
        if(height(tree.left) - height(tree.right) == 2){
            if(height(tree.left.left) > height(tree.left.right)){
                tree = L_L(tree)
            }else{
                tree = L_R(tree)
            }
        }
    }else if(key == tree.key){
        //此節點恰為要刪除的節點
        //第一次遇到時，先假設該節點左右子樹都不為空，開始進行替換
        if(tree.left && tree,right){
            if(tree.left.height > tree.right.height){
                var max_key = max_key_in_subtree(left)
                swap(max_key.key, tree.left.key)
                //目標刪除節點轉至max_key，繼續往下
                delete_node(tree.left, max_key.key)
            }else{
                var min_key = min_key_in_subtree(right)
                swap(min_key.key, tree.right.key)
                //目標刪除節點轉至min_key，繼續往下
            }
        }
        //第二次遇到，這時他已經位於底層(必定有一邊子樹為空)
        else{
            if(tree.left){
                tree = tree.left
            }else if(tree.right){
                tree = tree.right
            }else{
                tree = null
            }
            tree.height = 0
        }
    }
    return tree
}