#ifndef SPAN_H
#define SPAN_H
#include <vector>

class Span {
public:
    Span();
    Span(unsigned int size);
    ~Span();

    Span(const Span&);
    Span& operator=(const Span&);

    void addNumber(int number);
    template<typename Iterator>
    void addNumbers(Iterator begin, Iterator end);
    int shortestSpan() const;
    int longestSpan() const;
    unsigned int getSize() const;

private:
    std::vector<int> m_numbers;
    unsigned int m_size;

    std::vector<int> sortNumbers() const;
};

template<typename Iterator>
void Span::addNumbers(Iterator begin, Iterator end) {
    size_t size = std::distance(begin, end);
    if (m_numbers.size() + size > m_size) {
        throw std::length_error("Span is full, cannot add more numbers.");
    }
    m_numbers.insert(m_numbers.end(), begin, end);
}

#endif // SPAN_H
