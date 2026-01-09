#include "ast.hxx"
#include "token.hxx"
#include <iostream>

namespace AST
{

std::unordered_map<std::string, Type> Type::BuiltInTypes = {
	{
		"u8",
		{
			TypeSize::Byte,
			false,
		},
	},
	{
		"u16",
		{
			TypeSize::Word,
			false,
		},
	},
	{
		"u32",
		{
			TypeSize::DWord,
			false,
		},
	},
	{
		"u64",
		{
			TypeSize::QWord,
			false,
		},
	},
	{
		"i8",
		{
			TypeSize::Byte,
			true,
		},
	},
	{
		"i16",
		{
			TypeSize::Word,
			true,
		},
	},
	{
		"i32",
		{
			TypeSize::DWord,
			true,
		},
	},
	{
		"i64",
		{
			TypeSize::QWord,
			true,
		},
	},

};

void AddVar(Token::Stream &stream)
{
	Var var;
	var.constant = stream.NextIfMatch("mut");
	var.references = stream.NextIfMatch("&");
	stream.StreamIn(var.name);
	if (stream.NextIfMatch(":"))
	{
		var.type = &Type::BuiltInTypes.at(stream.GetToken());
		stream.NextToken();
	}
	else
	{
		var.type = nullptr;
	}
	stream.NextToken();
	std::cout << "Added var of name " << var.name << " and type size " << int(var.type->size)
			  << (var.constant ? "'constant var'\n" : "\n");
}

Scope GenScope(Token::Stream &stream)
{
	Scope out;
	std::cout << "Building scope\n";

	stream.NextToken();

	while (stream.GetToken().size())
	{
		std::cout << stream.GetToken() << "\n";

		if (stream.NextIfMatch("fn"))
		{
			Function func;
			stream.StreamIn(func.name);
			std::cout << "Function named " << func.name << "\n";
			stream.NextToken();
		}
		else if (stream.NextIfMatch("let"))
		{
			AddVar(stream);
		}

		stream.NextToken();
	}

	return out;
}

Root Generate(Token::Stream &stream)
{
	Root root;

	root.content = GenScope(stream);

	return root;
}

Root::Root()
{
	content.parent = nullptr;
}

} // namespace AST