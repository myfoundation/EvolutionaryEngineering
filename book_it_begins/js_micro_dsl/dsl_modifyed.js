

// =======================================================================
/*
########   ######  ##           ######   #######  ##       ##       ########  ######  ######## ####  #######  ##    ## 
##     ## ##    ## ##          ##    ## ##     ## ##       ##       ##       ##    ##    ##     ##  ##     ## ###   ## 
##     ## ##       ##          ##       ##     ## ##       ##       ##       ##          ##     ##  ##     ## ####  ## 
##     ##  ######  ##          ##       ##     ## ##       ##       ######   ##          ##     ##  ##     ## ## ## ## 
##     ##       ## ##          ##       ##     ## ##       ##       ##       ##          ##     ##  ##     ## ##  #### 
##     ## ##    ## ##          ##    ## ##     ## ##       ##       ##       ##    ##    ##     ##  ##     ## ##   ### 
########   ######  ########     ######   #######  ######## ######## ########  ######     ##    ####  #######  ##    ## 
*/
// =======================================================================

// DSL COLLECTION. SEE SAMPLES AT END OF FILE


// =======================================================================
/*
      ##  ######   #######  ##    ## ########    ########   ######  ##       
      ## ##    ## ##     ## ###   ##    ##       ##     ## ##    ## ##       
      ## ##       ##     ## ####  ##    ##       ##     ## ##       ##       
      ##  ######  ##     ## ## ## ##    ##       ##     ##  ######  ##       
##    ##       ## ##     ## ##  ####    ##       ##     ##       ## ##       
##    ## ##    ## ##     ## ##   ###    ##       ##     ## ##    ## ##       
 ######   ######   #######  ##    ##    ##       ########   ######  ######## 
*/
// =======================================================================

//------------------------------------------
// JSONT DSL DESCRIPTION
//------------------------------------------
// /* kb:Concept:MVC */ /* kb:DSL:JsontDSL */ /* kb:Explain */
/*
JSONT - это аналог XSLT для данных в формате JSON.

Принцип JSONT: вложение в заданное JSONT-правилами дерево
данных из JSON дерева.
=
Посредством JSONT-правил задаётся дерево, в это дерево вкладываются данные из дерева JSON.

При этом имя JSONT-правила - соответствует пути (для поиска) элемента в дереве JSON.
Алгоритм:
JSONT-процессор начинает движение по дереву JSONT-правил, направляя в корневое правило (если оно есть) корень JSON-объекта.
1. Когда JSONT-процессор встречает заключенное в скобки выражение вида {xxxxxx}, он пытается вычислить его
сначала
а) используя соответствующее xxxxxx JSONT-правило, передав в него соотетствующий xxxxxx JSONT-правилу JSON-объект из JSON-дерева ($)
б) если правила, соответствующего указанному в {} имени не находится, вместо него подставляется значение (по пути xxxxxx) из JSON-дерева,
2. Когда JSONT-процессор выбирет узел из JSON-дерева, он пытается найти и применить к нему
соответствующее его пути JSONT-правило
*/

/*
// EXPLAIN. SAMPLE WITH FULLPATHES TO OBJECT ITEMS

// JSONT IS XSLT ( https://ru.wikipedia.org/wiki/XSLT ) FOR JSON
// XSLT USE XPath ( https://ru.wikipedia.org/wiki/XPath ) FOR ACCESS BY XPath-NAME TO NODES OF TREE
// XSLT PROCESSOR GO BY XML-TREE AND PALLY RULES TO NODE WHICH PATH AT THE SAME TIME IS A RULE NAME

// NAMED NODES
var arr =
[{
	'markers': 'some text',
	'markers_text': ['unique','beauty']
}];

// FULLPATHES (XPath-NAMES) TO NODES WITH HTML WPARERS
var rules =
{
	'self': '{$}',	// self MEAN ROOT RULE / ROOT OF JSON OBJECT (FIRST AND ALWAYS DEFAULT-USED RULE)
	'self[*]' :		// APPLYED TO ITEMS IF ARRAY, $ MEAN CURRENT PROCESSING ITEM
	`
		<h4>{$.markers}</h4>
		<h4>{$.markers_text}</h4>
	`,
	// JSON KEY MATCH RULE NAME (markers AT THE SAME TIME IS A KEY AND IS A RULE NAME)
	'self[*].markers': '<p>{$}</p>',
	'self[*].markers_text': '<div>{$}</div>', // FULPATH TO markers_text KEY
	'self[*].markers_text[*]': '<span>{$}</span>' // FULPATH TO markers_text KEY ITEMS
};

jsonT(arr,rules);
"
	<h4><p>some text</p></h4>
	<h4><div><span>unique</span><span>beauty</span></div></h4>
"
*/

/*	This work is licensed under Creative Commons GNU LGPL License.

	License: http://creativecommons.org/licenses/LGPL/2.1/
	Version: 0.9
	Author:  Stefan Goessner/2006
	Web:     http://goessner.net/ 
*/
/*
============================
 Basic Rules
============================
A set of transformation rules is written using the object literal notation. So each rule is a name/value pair. The rule name usually is an expression for accessing an object member. The rule value is either a string or a function with a single argument, which are evaluated at transformation time.

"name": "transformation string" "name": function(arg){ - }

The transformation string itself can contain one or more expressions enclosed in curly braces

{expr}

which always resolve to a string value. 
  * If expr references a rule name, it results in either the transformation string or the return value of the implicit transformation function of that rule. 
  * If expr evaluates to a primitive data type, its value is converted to a string. 
  * If expr evaluates to an array/object, each array element/object member is processed accordingly. 
  * The shortcut $ as part of the expr is substituted by the rule name. 
  * If expr has the explicit form @name(expr), the function belonging to the rule name is called and its return value is converted to a string.
The outer JSON object can be accessed using the keyword self.

Rule names for array elements use the syntax name[*]. When using the $ shortcut in transformation string, the '*' resolves to the actual array index.

Object members, which have no transformation rule assigned and are not directly or indirectly referenced, as well as expressions evaluating to undefined don't create output. 
*/
/*
	FEATURES:

	1. STORING/RESTORING FUNCTIONS IN RULES
	IF RULE NAME STARTS FROM @xxxxx THE FUNCTION WITH NAME xxxxx BE CREATED

	2. PUT + IN expr FOR HTML ECRAN EVALUTES RESULT F.E. {+pnt.x} OR {+@icon(pnt.x)}

	3. IF YOU NEED CALL FUNC WITHOUT PARAMS, CALL FUNC WITH 1 PARAM LIKE THIS:
	var r = {
				"self[*]": "src='{@icon($)}'\n",
				"icon": function(){ return 'some const'; }           
	        };
*/
function jsonT(self, rules)
{
	var T =
	{
	output: false,
	init: function()
	{
		//------------------------------------------
		// APPEND FUNCTIONS FROM STRING
		//------------------------------------------
		/*
		IF RULE NAME STARTS FROM @xxxxx THE FUNCTION WITH NAME xxxxx BE CREATED
		*/
		var rules_1 = null;
		if(rules)
		{
			rules_1 = {};
			for (var k in rules)
			{
				if (!rules.hasOwnProperty(k)) continue;
				if(k.charAt(0) == '@')
				{
					rules_1[k.substr(1)] = (typeof rules[k] === 'string') ? Convert.s2fn(rules[k]):rules[k];
				}
				else rules_1[k] = rules[k];
			}
			rules = rules_1;
		}
		//------------------------------------------
	
		for (var rule in rules)
			if (rule.substr(0,4) != "self")
				rules["self."+rule] = rules[rule];
		return this;
	},
	apply: function(expr)
	{
		var trf = function(s){ return s.replace(/{([A-Za-z0-9_\$\.\[\]\'@\+\(\)]+)}/g, 
									function($0,$1){return T.processArg($1, expr);})},
			x = expr.replace(/\[[0-9]+\]/g, "[*]"), res;
		if (x in rules)
		{
			if (typeof(rules[x]) == "string")
				res = trf(rules[x]);
			else if (typeof(rules[x]) == "function")
				res = trf(rules[x](eval(expr)).toString());
		}
		else 
			res = T.eval(expr);
		return res;
	},
	
	processArg: function(arg, parentExpr)
	{
		var expand = function(a,e){return (e=a.replace(/^\$/,e)).substr(0,4)!="self" ? ("self."+e) : e; },
			res = "";
		T.output = true;
		
		//------------------------------------------
		// ECRAN
		var ecran = false;
		if(arg.charAt(0) == "+")
		{
			arg = arg.substr(1);
			ecran = true;
		}
		//------------------------------------------
		
		if (arg.charAt(0) == "@")
		{
			res = eval(arg.replace(/@([A-za-z0-9_]+)\(([A-Za-z0-9_\$\.\[\]\']+)\)/, 
									function($0,$1,$2)
									{
										var farg = expand($2,parentExpr);
										
										//------------------------------------------
										// PASS KEY AND LIST TO FUNCTION
										if(farg.lastIndexOf("]") == farg.length-1)
										{
											var key = farg.lastIndexOf("[");
											farg += (',' + farg.substr(key+1, farg.length-key-2) + ',' + farg.substr(0, key));
										}
										//------------------------------------------
										
										return "rules['self."+$1+"']("+farg+")";
									}));
		}
		else if (arg != "$")
			res = T.apply(expand(arg, parentExpr));
		else
			res = T.eval(parentExpr);

		// ECRAN
		if(ecran) res = Convert.escape(res, 'escapeHtml');
			
		T.output = false;
		return res;
	},
	
	eval: function(expr)
	{
		var v = eval(expr), res = "";
		if (typeof(v) != "undefined")
		{
			if (v instanceof Array)
			{
				for (var i=0; i<v.length; i++)
				{
					if (typeof(v[i]) != "undefined")
						res += T.apply(expr+"["+i+"]");
				}
			}
			else if (typeof(v) == "object")
			{
				for (var m in v)
				{
					if (typeof(v[m]) != "undefined")
						res += T.apply(expr+"."+m);
				}
			}
			else if (T.output)
			{
				res += v;
			}
		}
		return res;
	}
	};
	return T.init().apply("self");
}

// =======================================================================
/*
      ##  ######   #######  ##    ## ########     ###    ######## ##     ##    ########   ######  ##       
      ## ##    ## ##     ## ###   ## ##     ##   ## ##      ##    ##     ##    ##     ## ##    ## ##       
      ## ##       ##     ## ####  ## ##     ##  ##   ##     ##    ##     ##    ##     ## ##       ##       
      ##  ######  ##     ## ## ## ## ########  ##     ##    ##    #########    ##     ##  ######  ##       
##    ##       ## ##     ## ##  #### ##        #########    ##    ##     ##    ##     ##       ## ##       
##    ## ##    ## ##     ## ##   ### ##        ##     ##    ##    ##     ##    ##     ## ##    ## ##       
 ######   ######   #######  ##    ## ##        ##     ##    ##    ##     ##    ########   ######  ######## 
*/
// =======================================================================

//------------------------------------------
// JSONPath DSL. JSONPath - XPath for JSON
//------------------------------------------
// /* kb:DSL:JSONPathDSL */ /* kb:Concept:Accessors */

/* JSONPath 0.8.0 - XPath for JSON
 *
 * Copyright (c) 2007 Stefan Goessner (goessner.net)
 * Licensed under the MIT (MIT-LICENSE.txt) licence.
 
 JSONPath 0.8.6
 9:50 28.04.2020 ANONYMOUS
 SOME IMPOUVMENTS ADDED
 
 JSONPath 0.8.5
 1:31 09.01.2017 ANONYMOUS
 SOME IMPOUVMENTS ADDED
 
 JSONPath 0.8.1
 19:02 24.06.2016 ANONYMOUS
 BUG FIXED
 in 0.8.0 version only one argument in func in expression () allowed
 f.e. $.CMD[?(myfunc(1, 2))] will fail
 in 0.8.1 version this sample work correct

 */

/*
============================
Introducing XPath for JSON
============================

The following XPath expression

/store/book[1]/title

would look like

x.store.book[0].title

or

x['store']['book'][0]['title']

============================
 Basic Rules
============================

JSONPath expressions always refer to a JSON structure in the same way as XPath expression are used in combination with an XML document. Since a JSON structure is usually anonymous and doesn't necessarily have a "root member object" JSONPath assumes the abstract name $ assigned to the outer level object.

JSONPath expressions can use the dot-notation

$.store.book[0].title

or the bracket-notation

$['store']['book'][0]['title']

for input pathes. Internal or output pathes will always be converted to the more general bracket-notation.

JSONPath allows the wildcard symbol * for member names and array indices. It borrows the descendant operator '..' from {E4X} and the {array slice syntax} proposal [start:end:step] from {ECMASCRIPT 4}.

Expressions of the underlying scripting language (<expr>) can be used as an alternative to explicit names or indices as in

$.store.book[(@.length-1)].title

using the symbol '@' for the current object. Filter expressions are supported via the syntax ?(<boolean expr>) as in

$.store.book[?(@.price < 10)].title

Here is a complete overview and a side by side comparison of the JSONPath syntax elements with its XPath counterparts.
XPath	 JSONPath		 Description  
/		 $				the root object/element  
.		 @				the current object/element  
/		 . or []			child operator  
..		 n/a				parent operator  
//		 ..				recursive descent. JSONPath borrows this syntax from E4X.  
*		 *				wildcard. All objects/elements regardless their names.  
@		 n/a				attribute access. JSON structures don't have attributes.  
[]		 []				subscript operator. XPath uses it to iterate over element collections and for {predicates}. In Javascript and JSON it is the native array operator.  
|		 [,]				Union operator in XPath results in a combination of node sets. JSONPath allows alternate names or array indices as a set.  
n/a		 [start:end:step]	array slice operator borrowed from ES4.  
[]		 ?()				applies a filter (script) expression.  
n/a		 ()				script expression, using the underlying script engine.  
()		 n/a				grouping in Xpath 

XPath has a lot more to offer (Location pathes in not abbreviated syntax, operators and functions) than listed here. Moreover there is a remarkable difference how the subscript operator works in Xpath and JSONPath.
  * Square brackets in XPath expressions always operate on the node set resulting from the previous path fragment. Indices always start by 1. 
  * With JSONPath square brackets operate on the object or array addressed by the previous path fragment. Indices always start by 0. 
*/

/**
@arg MAY BE STRING 'FLAGS' OR OBJECT { resultType : 'FLAGS' } WHERE 'FLAGS' IS STRING = [VALUE PATH KEY ONE] OR IT'S COMBINATION DIVIDED BY '-' F.E. 'VALUE-ONE'
*/
function jsonPath(obj, expr, arg, def_val)
{
	var jsonPathFL = 
	{
		// USE 'VALUE-PATH-KEY-ONE' IN arg.resultType PARAM
		
		EMPTY		: 0,		// JUST EMPTY FLAG
		
		VALUE		: 1 << 0,	// Get Values
		PATH		: 1 << 1,	// Get Paths
		ONE			: 1 << 2,	// Get only IF One Value, OR RETURN def_val
		KEY			: 1 << 3	// Get only Keys USE ONLY WITH paths
	};

	var P = {
	resultType: 0,
	result: [],
	normalize: function(expr){
		var subx = [];
		return expr.replace(/[\['](\??\(.*?\))[\]']/g, function($0,$1){return "[#"+(subx.push($1)-1)+"]";})
				.replace(/'?\.'?|\['?/g, ";")
				.replace(/;;;|;;/g, ";..;")
				.replace(/;$|'?\]|'$/g, "")
				.replace(/#([0-9]+)/g, function($0,$1){return subx[$1];});
	},
	asPath: function(path)
	{
		var x = path.split(";"), p = "$";
		var n=x.length;
		
		if(n && (P.resultType & jsonPathFL.KEYs)) return x[n-1];
		
		for (var i=1; i<n; i++) p += /^[0-9*]+$/.test(x[i]) ? ("["+x[i]+"]") : ("['"+x[i]+"']");
		return p;
	},
	store: function(p, v) {
		if (p) P.result[P.result.length] = (P.resultType & jsonPathFL.PATH) ? P.asPath(p) : v;
		return !!p;
	},
	trace: function(expr, val, path) {
		if (expr) {
		var x = expr.split(";"), loc = x.shift();
		x = x.join(";");
		if (val && val.hasOwnProperty(loc))
			P.trace(x, val[loc], path + ";" + loc);
		else if (loc === "*")
			P.walk(loc, x, val, path, function(m,l,x,v,p) { P.trace(m+";"+x,v,p); });
		else if (loc === "..") {
			P.trace(x, val, path);
			P.walk(loc, x, val, path, function(m,l,x,v,p) { typeof v[m] === "object" && P.trace("..;"+x,v[m],p+";"+m); });
		}
		else if (/^\(.*?\)$/.test(loc)) // [(expr)]
			P.trace(P.eval(loc, val, path.substr(path.lastIndexOf(";")+1))+";"+x, val, path);
		else if (/^\?\(.*?\)$/.test(loc)) // [?(expr)]
			P.walk(loc, x, val, path, function(m,l,x,v,p) { if (P.eval(l.replace(/^\?\((.*?)\)$/,"$1"),v[m],m)) P.trace(m+";"+x,v,p); });
		else if (/,/.test(loc)) { // [name1,name2,...]
			for (var s=loc.split(/'?,'?/),i=0,n=s.length; i<n; i++)
			P.trace(s[i]+";"+x, val, path);
		}
		else if (/^(-?[0-9]*):(-?[0-9]*):?([0-9]*)$/.test(loc)) // [start:end:step]	phyton slice syntax
			P.slice(loc, x, val, path);
		}
		else
		P.store(path, val);
	},
	walk: function(loc, expr, val, path, f) {
		if (val instanceof Array) {
		for (var i=0,n=val.length; i<n; i++)
			if (i in val)
			f(i,loc,expr,val,path);
		}
		else if (typeof val === "object") {
		for (var m in val)
			if (val.hasOwnProperty(m))
			f(m,loc,expr,val,path);
		}
	},
	slice: function(loc, expr, val, path) {
		if (val instanceof Array) {
		var len=val.length, start=0, end=len, step=1;
		loc.replace(/^(-?[0-9]*):(-?[0-9]*):?(-?[0-9]*)$/g, function($0,$1,$2,$3){start=parseInt($1||start);end=parseInt($2||end);step=parseInt($3||step);});
		start = (start < 0) ? Math.max(0,start+len) : Math.min(len,start);
		end	= (end < 0) ? Math.max(0,end+len) : Math.min(len,end);
		for (var i=start; i<end; i+=step)
			P.trace(i+";"+expr, val, path);
		}
	},
	eval: function(x, _v, _vname) {
		try { return $ && _v && eval(x.replace(/@/g, "_v")); }
		catch(e) { throw new SyntaxError("jsonPath: " + e.message + ": " + x.replace(/@/g, "_v").replace(/\^/g, "_a")); }
	}
	};
	
	def_val = (typeof def_val === "undefined") ? false : def_val;
	P.resultType = jsonPathFL.VALUE;
	
	//------------------------------------------
	// ADDITIONAL PARAMS PROCESSING
	if(arg)
	{
		var flags = (typeof arg === "string") ? arg : arg.resultType;
		flags = flags.split('-');
		
		if(flags.length)
		{
			P.resultType = jsonPathFL.EMPTY;
			flags.forEach(function (v,k,l) { P.resultType |= jsonPathFL[v]; });
		}
	}
	//------------------------------------------

	var $ = obj;
	if (expr && obj && (P.resultType & (jsonPathFL.VALUE | jsonPathFL.PATH)))
	{
		P.trace(P.normalize(expr).replace(/^\$;/,""), obj, "$");
		
		if(P.resultType & jsonPathFL.ONE)
		{
			if(P.result.length == 1) return P.result[0];
			else return def_val;
		}
		
		return P.result.length ? P.result : def_val;
	}
	
	return def_val;
}


// =======================================================================
/*
########  ########  ######   ######  ########  #### ########  ######## ####  #######  ##    ##      ####        ######     ###    ##     ## ########  ##       ########  ######  
##     ## ##       ##    ## ##    ## ##     ##  ##  ##     ##    ##     ##  ##     ## ###   ##     ##  ##      ##    ##   ## ##   ###   ### ##     ## ##       ##       ##    ## 
##     ## ##       ##       ##       ##     ##  ##  ##     ##    ##     ##  ##     ## ####  ##      ####       ##        ##   ##  #### #### ##     ## ##       ##       ##       
##     ## ######    ######  ##       ########   ##  ########     ##     ##  ##     ## ## ## ##     ####         ######  ##     ## ## ### ## ########  ##       ######    ######  
##     ## ##             ## ##       ##   ##    ##  ##           ##     ##  ##     ## ##  ####    ##  ## ##          ## ######### ##     ## ##        ##       ##             ## 
##     ## ##       ##    ## ##    ## ##    ##   ##  ##           ##     ##  ##     ## ##   ###    ##   ##      ##    ## ##     ## ##     ## ##        ##       ##       ##    ## 
########  ########  ######   ######  ##     ## #### ##           ##    ####  #######  ##    ##     ####  ##     ######  ##     ## ##     ## ##        ######## ########  ######  
*/
// =======================================================================

//------------------------------------------
// SAMPLE SECTION
//------------------------------------------
/*
<html>
<head>
<title> JSONT - Tests </title>
<script type="text/javascript" src="jsont.js"></script>
<script type="text/javascript">

var o = [], t = [];

t[1] = { "self": "<table>{pnt}</table>",
         "pnt": "<tr><td>{pnt.x}</td><td>{pnt.y}</td></tr>" };
o[1] = { pnt: { x:2, y:3 }};

t[2] = { "self": "<table><tr>{$}</tr></table>",
         "self[*]": "<td>{$}</td>" };
o[2] = [ 1, 2 ];

t[3] = { "self": "<table>\n{$}\n</table>",
          "self[*]": "<tr>{$}</tr>\n",
          "self[*][*]": "<td>{$}</td>" };
o[3] = [[1,2],[3,4]];

t[4] = { "self": "<div>\n{p}\n</div>",
          "p": "<table><tr>{$}</tr></table>\n",
          "p[*]": "<td>{$.x}</td><td>{$.y}</td>" };
o[4] = {a:"hello", p:[{x:1,y:2},{x:3,y:4}]};

t[5] = { "self": "<a href=\"{uri}\" title='{title}'>{$.title}</a>" };
o[5] = { uri:"http://somewhere.org", title:"somewhere homepage" };

t[6] = { "menu": "<menu>\n  <header>{menu.header}</header>\n{menu.items}</menu>",
         "menu.items[*]": function(x){
                            return x ? "  <item action=\""+x.id+" id=\""+x.id+"\">"+(x.label||x.id)+"</li>\n" 
                                     : "  <separator/>\n";} };
o[6] = {"menu": {
          "header": "SVG Viewer",
          "items": [
            {"id": "Open"},
            {"id": "OpenNew", "label": "Open New"},
            null,
            {"id": "ZoomIn", "label": "Zoom In"},
            {"id": "OriginalView", "label": "Original View"},
            null,
            {"id": "Quality"},
            {"id": "Mute"},
            null,
            {"id": "Help"},
            {"id": "About", "label": "About Adobe CVG Viewer..."}
    ]}};

t[7] = { "self": "<p> {a} {b} {c} {d} </p>" };
o[7] = { a:false, b:null, d:true };

t[8] = { "self": "<p> {a} </p>",
         "a": function(x) {return x ? 'black' : 'white';} };
o[8] = { "a": true };

t[9] = { "A": "<div>{A.a1} and {A.a2}</div>" };
o[9] = { "A" : { "a1": "a1val", "a2": "a2val" },
         "B" : { "b1": "b1val", "b2": "b2val" } };

o[10] = { "line": { "p1": {"x":2, "y":3},
                    "p2": {"x":4, "y":5} }};
t[10] = { "self": "<svg>{line}</svg>",
             "line": "<line x1=\"{$.p1.x}\" y1=\"{$.p1.y}\"" +
                           "x2=\"{$.p2.x}\" y2=\"{$.p2.y}\" />" };

o[11] = ["red", "green", "blue"];
t[11] = {"self": "<ul>\n{$}</ul>\n",
            "self[*]": "  <li>{$}</li>\n"};
o[12] = { "color": "blue",
          "closed": true,
          "points": [[10,10],[20,10],[20,20],[10,20]] };
t[12] = { "self": "<svg><{closed} stroke=\"{color}\" points=\"{points}\" /></svg>",
          "closed": function(x){return x ? "polygon" : "polyline";}, 
          "points[*][*]": "{$} " };

o[13] = {"menu": {
  "id": "file",
  "value": "File:",
  "popup": {
    "menuitem": [
      {"value": "New", "onclick": "CreateNewDoc()"},
      {"value": "Open", "onclick": "OpenDoc()"},
      {"value": "Close", "onclick": "CloseDoc()"}
    ]
  }
}};

t[13] = { "menu": "<menu id=\"{$.id}\" value=\"{$.value}\">\n"+
                  "  <popup>\n{$.popup.menuitem}  </popup>\n</menu>",
          "menu.popup.menuitem[*]": "    <menuitem value=\"{$.value}\""+
                                    "onclick=\"{$.onclick}\" />\n" };

o[14] = [{"u":"http://www.ericclapton.com/hello",
            "d":"Eric Clapton",
            "t":["guitarist","blues","rock"]},
           {"u":"http://www.bbking.com/",
            "d":"B.B. King : Official Site",
            "t":["guitarist","blues"]},
           {"u":"http://www.stevieraysbluesbar.com/",
            "d":"Louisville's House of Blues",
            "t":["guitarist","blues","rock"]}];

t[14] = { "self": "<ul>\n{$}</ul>",
          "self[*]": " <li>\n"+
                     "  <img style='position:absolute;display:none;'"+
                     "    width='16' height='16'\n"+
                     "    onload='showImage(this)' src='{@icon($.u)}'/>\n"+
                     "  <a style='margin-left:20px;' href='{$.u}'>{$.d}</a>\n"+
                     " </li>\n",
          "icon": function(x){return x.split('/').splice(0,3).join('/')+'/favicon.ico';}           
           };

t[15] = { "self": "<p> {$.a} </p>",
          "a": function(x){return x ? 'black' : 'white'} }
o[15] = { "a": true };

t[16] = { "self": "<p> {a}, {b}, {b.x} </p>",
          "b": "hello",
          "b.x": "" };
o[16] = { "a": false, "b": null };

t[17] = { "self": function(x){ return x.length; } }
o[17] = [ 1, 2, 1 ];

function test()
{
	var N1 = 1; // 1
	var N2 = 17; // 17
	
	for(var i=N1; i<N2+1; i++ )
	{
   		show(jsonT(o[i], t[i]));
   	}
}

function show(s) { document.getElementById("out").innerHTML += (s+"\n").replace(/&/g, "&amp;").replace(/</g,"&lt;").replace(/>/g,"&gt;").replace(/\n/g, "<br/>") + "<hr/>"; }
window.onload = test;
</script>
</head>

<body>
<pre id="out"></pre>
</body>
</html> 

*/

// ============================SECTION====================================
//------------------------------------------
// JSONPath DSL DECRIPTION
//------------------------------------------
//------------------------------------------
// SAMPLE SECTION
//------------------------------------------
/*
Let's practice JSONPath expressions by some more examples. We start with a simple JSON structure built after an XML example representing a bookstore (original {XML file}). 
{ "store": {
    "book": [ 
      { "category": "reference",
        "author": "Nigel Rees",
        "title": "Sayings of the Century",
        "price": 8.95
      },
      { "category": "fiction",
        "author": "Evelyn Waugh",
        "title": "Sword of Honour",
        "price": 12.99
      },
      { "category": "fiction",
        "author": "Herman Melville",
        "title": "Moby Dick",
        "isbn": "0-553-21311-3",
        "price": 8.99
      },
      { "category": "fiction",
        "author": "J. R. R. Tolkien",
        "title": "The Lord of the Rings",
        "isbn": "0-395-19395-8",
        "price": 22.99
      }
    ],
    "bicycle": {
      "color": "red",
      "price": 19.95
    }
  }
}
XPath				 JSONPath				 Result  
/store/book/author	$.store.book[*].author			the authors of all books in the store  
//author				$..author					all authors  
/store/*				$.store.*					all things in store, which are some books and a red bicycle.  
/store//price			$.store..price				the price of everything in the store.  
//book[3]				$..book[2]				the third book  
//book[last()]			$..book[(@.length-1)]	OR		$..book[-1:]				the last book in order.  
//book[position()<3]	$..book[0,1]			OR 		$..book[:2]	the first two books  
//book[isbn]			$..book[?(@.isbn)]		filter all books with isbn number  
//book[price<10]		$..book[?(@.price<10)]	filter all books cheapier than 10  
//*					$..*						all Elements in XML document. All members of JSON structure. 

jsonPath(obj, expr [, args])

parameters:
obj (object|array):
Object representing the JSON structure.
expr (string):
JSONPath expression string.
args (object|undefined):
Object controlling path evaluation and output. Currently only one member is supported.
args.resultType ("VALUE"|"PATH"):
causes the result to be either matching values (default) or normalized path expressions.

return value: 
(array|false):
Array holding either values or normalized path expressions matching the input path expression, which can be used for lazy evaluation. false in case of no match.

Javascript Example: 
var o = { ... },  // the 'store' JSON object from above
	res1 = jsonPath(o, "$..author").toJSONString(),
	res2 = jsonPath(o, "/p/$..author").toJSONString();

*/
