#pragma once
#ifndef __Symbol_Table__
#define __Symbol_Table__
#include "MyMap.h"

enum structure {
	TYPE = 0,
	FUNCTION,
	DATAMEMBER,
	LOCALVARIABLE,
	PARAMETER
};

class Scope {
public:
	Scope();
	Scope * parent;
	MyMap * m;
	void* scopeOwner;
};
class Parameter {
private:
	int id;
	char* name;
	char* type;
	bool isFinal;
	static int lastId;
public:
	enum structure strc;
	Parameter* next;
	Parameter();
	Parameter(Parameter* parameter);
	~Parameter();
	void setId(int id);
	int getId();
	static void setLastId(int lastId);
	static int getLastId();
	static int lastIdInc();
	void setName(char* n);
	char* getName();
	void setType(char* type);
	char* getType();
	void setIsFinal(bool isFinal);
	bool getIsFinal();
	bool isPrimitiveType(char* type);
	bool equals(Parameter* p);
};
class ParamList {
private:
	Parameter* current;
	Parameter* root;
public:
	int size;
	ParamList();
	ParamList(ParamList* pl);
	~ParamList();
	Parameter* find(char* name);
	Parameter* add(Parameter* parameter);
	bool remove(char* name);
	bool equals(ParamList* pl);
	bool isEmpty();
	void print();
};
class Variable {
private:
	int id;
	char* name;
	char* type;
	char* alternativeType;
	bool isFinal;
	static int lastId;
public:
	int colNo;
	int rowNo;
	enum structure strc;
	Variable();
	~Variable();
	void setId(int id);
	int getId();
	void setName(char* n);
	char* getName();
	void setType(char* type);
	char* getType();
	void setAlternativeType(char* type);
	char* getAlternativeType();
	void setIsFinal(bool isFinal);
	bool getIsFinal();
	static void setLastId(int lastId);
	static int getLastId();
	static int lastIdInc();
	bool isPrimitiveType(char* type);
};

class DataMember {
private:
	int id;
	char* name;
	char* type;
	bool isFinal;
	bool isStatic;
	bool isPublic;
	bool isPrivate;
	bool isProtected;
	void initModifiers();
	static int lastId;
public:
	int colNo;
	int rowNo;
	enum structure strc;
	DataMember();
	~DataMember();
	void setId(int id);
	int getId();
	void setName(char* n);
	char* getName();
	void setType(char* type);
	char* getType();
	void setIsPublic(bool isPublic);
	bool getIsPublic();
	void setIsPrivate(bool isPrivate);
	bool getIsPrivate();
	void setIsProtected(bool isProtected);
	bool getIsProtected();
	void setIsFinal(bool isFinal);
	bool getIsFinal();
	void setIsStatic(bool isStatic);
	bool getIsStatic();
	bool illegalCombinationOfModifiers();
	void printDetails();
	static void setLastId(int lastId);
	static int getLastId();
	static int lastIdInc();
};
class ErrorRecovery;
class Type {
private:
	int size;
	char* name;
	char* label;
	char* parentName;
	char* fileName;
	bool isPublic;
	bool isPrivate;
	bool isProtected;
	bool isFinal;
	bool isAbstract;
	bool isStatic;
	Type* inheritedType;
	Scope * scope;
public:
	Type* next;
	int colNo;
	int rowNo;
	enum structure strc;
	Type();
	~Type();
	void checkForAbstraction(ErrorRecovery* errRecovery);
	bool isCyclicInheritance(ErrorRecovery* errRecovery);
	void setSize(int size);
	int getSize();
	void setName(char* name);
	char* getName();
	void setLabel(char* label);
	char* getLabel();
	void setParentName(char* n);
	char* getParentName();
	void setFileName(char* n);
	char* getFileName();
	void setInheritedType(Type* e);
	Type* getInheritedType();
	void setIsFinal(bool isFinal);
	bool getIsFinal();
	void setIsStatic(bool isStatic);
	bool getIsStatic();
	void setIsPublic(bool isPublic);
	bool getIsPublic();
	void setIsPrivate(bool isPrivate);
	bool getIsPrivate();
	void setIsProtected(bool isProtected);
	bool getIsProtected();
	void setIsAbstract(bool isAbstract);
	bool getIsAbstract();
	bool illegalCombinationOfModifiers();
	void setScope(Scope * m);
	Scope * getScope();
	void printDetails();
	bool equals(Type* type);
};
class TypeList {
private:
	Type* current;
	Type* root;
public:
	int size;
	TypeList();
	TypeList(TypeList* tl);
	~TypeList();
	Type* find(char* name);
	Type* add(Type* type);
	bool remove(char* name);
	bool equals(TypeList* tl);
	bool isEmpty();
	void print();
};
class ErrorRecovery;
class Function {
private:
	int id;
	int size;
	static int lastId;
	char* label;
	char* name;
	int varCount;
	bool isPublic;
	bool isPrivate;
	bool isProtected;
	bool isStatic;
	bool isFinal;
	bool isAbstract;
	bool isNative;
	bool isSynchronized;
	bool isTransient;
	bool isVolatile;
	bool isConstructor;
	Scope * scope;
	char* returnType;
	void initModifiers();
public:
	int colNo;
	int rowNo;
	enum structure strc;
	ParamList* pl;
	Parameter** parameters;
	Function();
	~Function();
	bool equals(Function* f);
	void generateLabel(Type* t);
	void printDetails();
	int checkMethodBody(bool methodBody, ErrorRecovery* errRecovery);
	bool isOverloadingState(Function* f);
	bool constructorModifiersError();
	bool illegalCombinationOfModifiers();
	void setName(char* name);
	char* getName();
	void setLabel(char* label);
	char* getLabel();
	void setId(int id);
	int getId();
	void setSize(int size);
	int getSize();
	static void setLastId(int lastId);
	static int getLastId();
	static void lastIdInc();
	void setIsPublic(bool isPublic);
	bool getIsPublic();
	void setVarCount(int varCount);
	int getVarCount();
	void varCountInc();
	void setIsPrivate(bool isPrivate);
	bool getIsPrivate();
	void setIsProtected(bool isProtected);
	bool getIsProtected();
	void setIsStatic(bool isStatic);
	bool getIsStatic();
	void setIsFinal(bool isFinal);
	bool getIsFinal();
	void setIsAbstract(bool isAbstract);
	bool getIsAbstract();
	void setIsNative(bool isNative);
	bool getIsNative();
	void setIsSynchronized(bool isSynchronized);
	bool getIsSynchronized();
	void setIsTransient(bool isTransient);
	bool getIsTransient();
	void setIsVolatile(bool isVolatile);
	bool getIsVolatile();
	void setReturnType(char* returnType);
	char* getReturnType();
	void setScope(Scope* m);
	bool getIsConstructor();
	void setIsConstructor(bool isConstructor);
	Scope* getScope();
};
//=============================
class Modifier;
class ErrorRecovery;
class SymbolTable
{
private:
	void checkMethodOverriding(Scope* scope, int i, MapElem* elem, ErrorRecovery* errRecovery);
	void checkTypeInheritance(Scope* scope, MapElem* currElem, ErrorRecovery* errRecovery);
	void checkInnerInheritance(Scope* scope, Type* type, ErrorRecovery* errRecovery);
	void checkAbstractMethod(Scope* scope, int i, MapElem* elem, ErrorRecovery* errRecovery);
	void checkMainMethod(Scope* scope, int i, MapElem* elem, ErrorRecovery* errRecovery);
	void checkNexts(Scope* scope, int i, ErrorRecovery* errRecovery);

	void printNexts(Scope* scope, int index, ErrorRecovery* errRecovery);
	Type* printTypeHeader(Scope* scope, int index);
	Function* printMethodHeader(Scope* scope, int index, ErrorRecovery* errRecovery);
	DataMember* printDmHeader(Scope* scope, int index);
	Variable* printVarHeader(Scope* scope, int index);
public:
	Scope * currScope;
	Scope * rootScope;
	bool hasMainMethod;
	void checkFileClassNames(ErrorRecovery* errRecovery);
	void checkAtTheEnd(Scope* scope, MapElem* elem, ErrorRecovery* errRecovery);
	Type* getTypeParent(char* name);
	Type* getTypeParentByScope(Scope* scope, char* name);
	Variable * insertVariableInCurrentScope(char* name, Modifier* m, int lineNo, int colNo, ErrorRecovery* errRecovery);
	Variable * getVariableFromCurrentScope(char* name);
	Parameter * createParam(char* name, Modifier* m, ErrorRecovery* errRecovery);
	Parameter * getParameterFromCurrentFunction(char* name);
	DataMember * insertDataMemberInCurrentScope(char* name, Modifier* m, int lineNo, int colNo);
	DataMember * getDataMemberFromCurrentScope(char* name);
	void print(Scope* scope, ErrorRecovery* errRecovery);
	SymbolTable(void);
	~SymbolTable(void);
};
#endif