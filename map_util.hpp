#ifndef MAP_UTIL_HPP
#define MAP_UTIL_HPP

namespace ft{
    template    <class _NodePtr>
    _NodePtr	treeMin(_NodePtr	_start){
				_NodePtr StartingNode = _start;
				while (StartingNode->left != nullptr)
					StartingNode = StartingNode->left;
				return StartingNode;
			};

    template    <class _NodePtr>
    _NodePtr    treeMax(_NodePtr	_start){
		_NodePtr StartingNode = _start;
		while (StartingNode->right != nullptr)
			StartingNode = StartingNode->right;
		return StartingNode;
	};

	template <class _NodePtr>
	_NodePtr	tree_next_iter(_NodePtr S_Node){
		if(S_Node->right != nullptr)
			return treeMin(S_Node->right);
        _NodePtr    tmp = S_Node->parent;
        while (tmp != nullptr && S_Node == tmp->right)
        {
            S_Node = tmp;
            tmp = tmp->parent; 
        }
        return tmp;
	};
    template <class _NodePtr>
	_NodePtr	tree_prev_iter(_NodePtr S_Node){
		if(S_Node->left != nullptr)
			return treeMax(S_Node->left);
        _NodePtr    tmp = S_Node->parent;
        while (tmp != nullptr && S_Node == tmp->left)
        {
            S_Node = tmp;
            tmp = tmp->parent; 
        }
        return tmp;
	};
};

#endif /* MAP_UTIL_HPP */
