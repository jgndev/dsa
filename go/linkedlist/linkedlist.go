package linkedlist

import "fmt"

type Node struct {
	Val  int
	Next *Node
}

func NewNode(val int) *Node {
	return &Node{
		Val:  val,
		Next: nil,
	}
}

type LinkedList struct {
	Head *Node
	Tail *Node
}

func NewLinkedList() *LinkedList {
	node := NewNode(-1)

	return &LinkedList{
		Head: node,
		Tail: node,
	}
}

func (l *LinkedList) InsertEnd(val int) {
	l.Tail.Next = NewNode(val)
	l.Tail = l.Tail.Next
}

func (l *LinkedList) Remove(index int) {
	i := 0

	current := l.Head

	for i < index && current != nil {
		i++
		current = current.Next
	}

	if current != nil && current.Next != nil {
		if current.Next == l.Tail {
			l.Tail = current
		}

		current.Next = current.Next.Next
	}
}

func (l *LinkedList) Print() {
	current := l.Head.Next

	for current != nil {
		fmt.Printf("%d -> ", current.Val)
		current = current.Next
	}

	fmt.Println()
}
