using System;
using System.Collections.Generic;
using System.Linq;

namespace GenericHeap
{
    public class Heap<T>
    {
        private readonly List<T> _heap;
        private readonly Func<T, T, bool> ShouldSwap;
        public Heap(Func<T,T,bool> compareDelegate)
        {
            ShouldSwap = compareDelegate;
            _heap = new List<T>();
        }

        public void Insert(T item)
        {
            _heap.Add(item);
            BubbleUp(_heap.Count - 1);
        }

        public T Pop()
        {
            if (_heap.Count == 0) throw new IndexOutOfRangeException("Cannot pop item from an empty heap.");
            T root = _heap[0];
            int lastIndex = _heap.Count - 1;
            _heap[0] = _heap[lastIndex];
            _heap.RemoveAt(lastIndex);
            BubbleDown(0);
            return root;
        }
        
        public T Peek(){
        if (_heap.Count == 0) throw new IndexOutOfRangeException("Cannot pick item from an empty heap.");
            return _heap[0];
        }
        
        public bool IsEmpty()
        {
            return !_heap.Any();
        }

        private void BubbleDown(int index)
        {
            if (index >= _heap.Count - 1) return;

            int leftChildIndex = index * 2 + 1;
            int rightChildIndex = index * 2 + 2;

            if (leftChildIndex >= _heap.Count)
            {
                return;
            }

            int targetIndex = leftChildIndex;
            if (rightChildIndex < _heap.Count)
            {
                if (ShouldSwap(_heap[rightChildIndex], _heap[leftChildIndex]))
                {
                    targetIndex = rightChildIndex;
                }
            }

            if (ShouldSwap(_heap[index], _heap[targetIndex])) return;

            Swap(index, targetIndex);
            BubbleDown(targetIndex);
        }

        private void BubbleUp(int index)
        {
            if (index == 0) return;
            int parentIndex = (index - 1) / 2;
            if (ShouldSwap(_heap[index], _heap[parentIndex]))
            {
                Swap(index, parentIndex);
                BubbleUp(parentIndex);
            }
            else
            {
                return;
            }
        }

        private void Swap(int index1, int index2)
        {
            T swapTemp = _heap[index1];
            _heap[index1] = _heap[index2];
            _heap[index2] = swapTemp;
        }
    }
}
