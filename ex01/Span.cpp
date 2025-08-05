#include "Span.h"

Span::Span() {
    m_size = 0;
}

Span::Span(const unsigned int size) {
    m_size = size;
}

void Span::addNumber(const int number) {
    if (m_numbers.size() < m_size) {
        m_numbers.push_back(number);
    }
    else {
        throw std::length_error("Span is full, cannot add more numbers.");
    }
}

int Span::shortestSpan() const {
    if (m_size < 2) {
        throw std::logic_error("Not enough numbers to calculate span.");
    }
    std::vector<int> sorted_numbers = sortNumbers();
    int shortest_span = std::numeric_limits<int>::max();
    for (size_t i = 1; i < sorted_numbers.size(); ++i) {
        int span = sorted_numbers[i] - sorted_numbers[i - 1];
        if (span < shortest_span) {
            shortest_span = span;
        }
    }
    return shortest_span;
}

int Span::longestSpan() const {
    if (m_size < 2) {
        throw std::logic_error("Not enough numbers to calculate span.");
    }
    std::vector<int> sorted_numbers = sortNumbers();
    const int longest_span = sorted_numbers.back() - sorted_numbers.front();
    return longest_span;
}

unsigned int Span::getSize() const {
    return m_size;
}

std::vector<int> Span::sortNumbers() const {
    std::vector<int> numbers_copy = m_numbers;
    std::sort(numbers_copy.begin(), numbers_copy.end());
    return numbers_copy;
}

Span::~Span() {}

Span::Span(const Span& other) {
    this->m_numbers = other.m_numbers;
    this->m_size = other.m_size;
}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        this->m_numbers = other.m_numbers;
        this->m_size = other.m_size;
    }
    return *this;
}
