#include "detours.h"
#include <cassert>

struct IsEven {
    bool operator()(int value) const {
        return value % 2 == 0;
    }
};

struct IsVowel {
    bool operator()(char value) const {
        char c = std::tolower(value);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};

struct IsLongString {
    bool operator()(const std::string& value) const {
        return value.length() > 5;
    }
};


void testWhereInt() {
    Node<int>* root = nullptr;
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 4);

    Node<int>* filteredRoot = where(root, IsEven());

    assert(contains(root, 2));
    assert(contains(root, 4));
}

void testWhereChar() {
    Node<char>* root = nullptr;
    root = insert(root, 'a');
    root = insert(root, 'b');
    root = insert(root, 'c');
    root = insert(root, 'e');

    // Применяем операцию where с функцией-функтором IsVowel
    Node<char>* filteredRoot = where(root, IsVowel());

    assert(contains(root, 'a'));
}

void testWhereDouble() {
    Node<double>* root = nullptr;
    root = insert(root, 1.5);
    root = insert(root, 2.7);
    root = insert(root, 3.2);
    root = insert(root, 4.9);


    auto condition = [](double value) {
        return value > 3.0;
    };

    Node<double>* result = where(root, condition);

    assert(contains(result, 4.9));
    assert(!contains(root, 23.1));
    assert(!contains(root, 24.1));
    assert(!contains(root, 26.1));
    assert(!contains(root, 223.1));
}

void testInsert() {
    Node<int>* root = nullptr;
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 3);
    root = insert(root, 8);

    assert(contains(root, 10));
    assert(contains(root, 5));
    assert(contains(root, 15));
    assert(contains(root, 3));
    assert(contains(root, 8));
    assert(!contains(root, 20));
    assert(!contains(root, 23));
    assert(!contains(root, 24));
    assert(!contains(root, 26));
    assert(!contains(root, 223));
}

void testInsertDouble() {
    Node<double>* root = nullptr;
    root = insert(root, 10.1);
    root = insert(root, 5.1);
    root = insert(root, 15.1);
    root = insert(root, 3.1);
    root = insert(root, 8.1);

    assert(contains(root, 10.1));
    assert(contains(root, 5.1));
    assert(contains(root, 15.1));
    assert(contains(root, 3.1));
    assert(contains(root, 8.1));
    assert(!contains(root, 20.1));
    assert(!contains(root, 23.1));
    assert(!contains(root, 24.1));
    assert(!contains(root, 26.1));
    assert(!contains(root, 223.1));
}

void testInsertChar() {
    Node<char>* root = nullptr;
    root = insert(root, 'q');
    root = insert(root, 'w');
    root = insert(root, 'e');
    root = insert(root, 'r');
    root = insert(root, 't');

    assert(contains(root, 'q'));
    assert(contains(root, 'w'));
    assert(contains(root, 'e'));
    assert(contains(root, 'r'));
    assert(contains(root, 't'));
    assert(!contains(root, 'z'));
}

void testMerge() {
    Node<int>* root1 = nullptr;
    root1 = insert(root1, 5);
    root1 = insert(root1, 3);
    root1 = insert(root1, 8);

    Node<int>* root2 = nullptr;
    root2 = insert(root2, 10);
    root2 = insert(root2, 7);
    root2 = insert(root2, 12);

    Node<int>* merged = merge(root1, root2);

    assert(contains(merged, 5));
    assert(contains(merged, 3));
    assert(contains(merged, 8));
    assert(!contains(root1, 23));
    assert(!contains(root1, 24));
    assert(!contains(root1, 261));
    assert(!contains(root1, 2231));
}

void testMergeDouble() {
    Node<double>* root1 = nullptr;
    root1 = insert(root1, 5.1);
    root1 = insert(root1, 3.1);
    root1 = insert(root1, 8.1);

    Node<double>* root2 = nullptr;
    root2 = insert(root2, 10.1);
    root2 = insert(root2, 7.1);
    root2 = insert(root2, 12.1);

    Node<double>* merged = merge(root1, root2);

    assert(contains(merged, 5.1));
    assert(contains(merged, 3.1));
    assert(contains(merged, 8.1));
    assert(!contains(root1, 23.1));
    assert(!contains(root1, 24.1));
    assert(!contains(root1, 26.1));
    assert(!contains(root1, 223.1));
}

void testMergeChar() {
    Node<char>* root1 = nullptr;
    root1 = insert(root1, 'q');
    root1 = insert(root1, 'w');
    root1 = insert(root1, 'e');

    Node<char>* root2 = nullptr;
    root2 = insert(root2, 'r');
    root2 = insert(root2, 't');
    root2 = insert(root2, 'y');

    Node<char>* merged = merge(root1, root2);

    assert(contains(merged, 'q'));
    assert(contains(merged, 'w'));
    assert(contains(merged, 'e'));
}

void testExtractSubtree() {
    Node<int>* root = nullptr;
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 3);
    root = insert(root, 8);

    Node<int>* subtree = extractSubtree(root, 5);

    assert(contains(subtree, 5));
    assert(contains(subtree, 3));
    assert(contains(subtree, 8));
    assert(!contains(subtree, 10));
    assert(!contains(subtree, 15));
    assert(!contains(root, 23));
    assert(!contains(root, 24));
    assert(!contains(root, 26));
    assert(!contains(root, 223));
}

void testExtractSubtreeDouble() {
    Node<double>* root = nullptr;
    root = insert(root, 10.1);
    root = insert(root, 5.1);
    root = insert(root, 15.1);
    root = insert(root, 3.1);
    root = insert(root, 8.1);

    Node<double>* subtree = extractSubtree(root, 5.1);

    assert(contains(subtree, 5.1));
    assert(contains(subtree, 3.1));
    assert(contains(subtree, 8.1));
    assert(!contains(subtree, 10.1));
    assert(!contains(subtree, 15.1));
    assert(!contains(root, 23.1));
    assert(!contains(root, 24.1));
    assert(!contains(root, 26.1));
    assert(!contains(root, 223.1));
}

void testExtractSubtreeChar() {
    Node<char>* root = nullptr;
    root = insert(root, 'q');
    root = insert(root, 'w');
    root = insert(root, 'e');
    root = insert(root, 'r');
    root = insert(root, 't');

    Node<char>* subtree = extractSubtree(root, 'w');

    assert(contains(subtree, 'w'));
    assert(contains(subtree, 'r'));
    assert(contains(subtree, 't'));
    assert(!contains(subtree, 'q'));
    assert(!contains(subtree, 'e'));
}

void testMapInt() {
    Node<int>* root = nullptr;
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 4);

    Node<int>* mappedRoot = map(root, multiplyByTwo);

    assert(contains(mappedRoot, 2));
    assert(contains(mappedRoot, 4));
    assert(contains(mappedRoot, 6));
    assert(contains(mappedRoot, 8));
    assert(!contains(root, 231));
    assert(!contains(root, 241));
    assert(!contains(root, 261));
    assert(!contains(root, 2231));
}

void testMapDouble() {
    Node<double>* root = nullptr;
    root = insert(root, 1.1);
    root = insert(root, 2.1);
    root = insert(root, 3.1);
    root = insert(root, 4.1);

    Node<double>* mappedRoot = map(root, multiplyByTwoDouble);

    assert(contains(mappedRoot, 2.2));
    assert(contains(mappedRoot, 4.2));
    assert(contains(mappedRoot, 6.2));
    assert(contains(mappedRoot, 8.2));
    assert(!contains(root, 23.1));
    assert(!contains(root, 24.1));
    assert(!contains(root, 26.1));
    assert(!contains(root, 223.1));
}

void testMapChar() {
    Node<char>* root = nullptr;
    root = insert(root, 'a');
    root = insert(root, 'b');
    root = insert(root, 'c');
    root = insert(root, 'd');

    Node<char>* mappedRoot = map(root, charToNextAscii);

    assert(contains(mappedRoot, 'b'));
    assert(contains(mappedRoot, 'c'));
    assert(contains(mappedRoot, 'd'));
    assert(contains(mappedRoot, 'e'));
}


int main() {
    testInsert();
    testInsertDouble();
    testInsertChar();

    testMerge();
    testMergeChar();
    testMergeDouble();

    testExtractSubtree();
    testExtractSubtreeDouble();
    testExtractSubtreeChar();

    testMapInt();
    testMapDouble();
    testMapChar();

    testWhereInt();
    testWhereChar();
    testWhereDouble();

    cout << "All tests passed successfully!" << endl;

    return 0;
}

