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
            BubbleUp();
        }

        public T Pop()
        {
            if (_heap.Count == 0) throw new IndexOutOfRangeException("Cannot pop item from empty heap.");
            T root = _heap[0];
            int lastIndex = _heap.Count - 1;
            _heap[0] = _heap[lastIndex];
            _heap.RemoveAt(lastIndex);
            BubbleDown();
            return root;
        }
        
        public bool IsEmpty()
        {
            return !_heap.Any();
        }

        private void BubbleDown()
        {
            CheckChild(0);
        }
        private void BubbleUp()
        {
            CheckParent(_heap.Count-1);
        }

        void CheckChild(int index)
        {
            if (index >= _heap.Count - 1) return;

            int leftChildIndex = index * 2 + 1;
            int rightChildIndex = index * 2 + 2;

            if (leftChildIndex >= _heap.Count) {
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
            CheckChild(targetIndex);
        }

        private void CheckParent(int index)
        {
            if (index == 0) return;
            int parentIndex = (index -1) / 2;
            if(ShouldSwap(_heap[index], _heap[parentIndex]))
            {
                Swap(index, parentIndex);
                CheckParent(parentIndex);
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
