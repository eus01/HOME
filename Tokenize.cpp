#include "Tokenize.h"
#include <iostream>


namespace Noah {



	void Tokenize(const std::string& str, std::vector<std::string>& tokens, const std::string& delimiters)
	{
		std::string::size_type lastPos = str.find_first_not_of(delimiters, 0);
		std::string::size_type pos     = str.find_first_of(delimiters, lastPos);

		while (std::string::npos != pos || std::string::npos != lastPos)
		{
			tokens.push_back(str.substr(lastPos, pos - lastPos));
			lastPos = str.find_first_not_of(delimiters, pos);
			pos = str.find_first_of(delimiters, lastPos);
		}
	}


	Tokenizer::Tokenizer(const std::string& str, const std::string& delimiter) : m_str(str), m_strDelimiter(delimiter)
	{
		m_lastPos = m_str.find_first_not_of(m_strDelimiter, 0);
		m_currPos = m_str.find_first_of(m_strDelimiter, m_lastPos);

		// std::cout << "Tokenizer::Tokenizer() " << str_ << ", " << delimiter_ << ", " << lastPos_ << ", " << currPos_ << std::endl;
	}

	Tokenizer::~Tokenizer()
	{

	}


	bool Tokenizer::HasMoreTokens() const
	{
		if(std::string::npos != m_currPos || std::string::npos != m_lastPos)
		{
			return true;
		}

		return false;
	}


	const std::string Tokenizer::NextToken()
	{
		if(HasMoreTokens() == false)
		{
			return NULL;
		}

		// std::cout << "Tokenizer::NextToken() " << str_ << ", " << delimiter_ << ", " << lastPos_ << ", " << currPos_ << std::endl;

		const std::string str = m_str.substr(m_lastPos, m_currPos - m_lastPos);
		m_lastPos = m_str.find_first_not_of(m_strDelimiter, m_currPos);
		m_currPos = m_str.find_first_of(m_strDelimiter, m_lastPos);

		return str;
	}




}

