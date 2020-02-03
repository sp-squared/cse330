#ifndef INTERFACE_H
#define  INTERFACE_H
class IntCell{
public:
        explicit IntCell(int InitialValue = 0);
        int IntRead() const;
        void IntWrite(int x);
private:
        int StoredValue;
};
#endif
