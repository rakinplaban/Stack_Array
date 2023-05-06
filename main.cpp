#include <iostream>

using namespace std;

const int MAX_ITEMS = 5;

class EmptyStack{};

class FullStack{};

template <class ItemType>
class StackArray{
private:
    int top;
    ItemType arr[MAX_ITEMS];
public:
    StackArray(){
        top = -1;
    }

    bool isEmpty(){
        return (top == -1);
    }

    bool isFull(){
        return (top == MAX_ITEMS-1);
    }

    void pushStack(ItemType data){
        if(isFull()){
            throw FullStack();
        }else{
            top++;
            arr[top] = data;
        }
    }

    void popStack(){
        if(isEmpty()){
            throw EmptyStack();
        }else{
            top--;
        }
    }

    ItemType topData(){
        if(isEmpty()){
            throw EmptyStack();
        }
        else{
            return arr[top];
        }
    }

    void display(){
        if(isEmpty()){
            throw EmptyStack();
        }
        else{
            for(int i=0;i<=top;i++){
                cout << arr[i] <<" ";
            }
            cout <<endl;
        }
    }

};

int main()
{
    StackArray<int> s;
    s.pushStack(5);
    s.pushStack(8);
    s.pushStack(9);
    s.pushStack(12);
    s.popStack();
    cout << "Top of the stack : " << s.topData()<<endl;
    s.display();
    return 0;
}
