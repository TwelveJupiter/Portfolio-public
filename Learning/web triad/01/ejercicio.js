typeof "hola"      // "string"
typeof 42          // "number"
typeof NaN         // "number"  ← "Not a Number" es de tipo number
typeof undefined   // "undefined"
typeof null        // "object"  ← bug de 1995 que nunca se corrigió
typeof []          // "object"  ← para arrays se usa Array.isArray([])
typeof function(){} // "function"