---
title: "Intermediate html css"
date: 2024-12-11
---

# Custom Properties
- allow us to reference a CSS value however many times we want throughout a file.

## Syntax:
```css
.error-modal{
    --color-error-text: red;
    --modal-border: 1px solid black;
    --modal-font-size: calc(2rem + 5vw);

    color: var(--color-error-text);
    border: var(--modal-border);
    font-size: var(--modal-font-size);
}
```
- The double hyphen followed by a case-sensitive, hyphen separated property name.

## Fallback Values:
The `var()` function accepts two parameters, the first we've already
gone over. The second parameter is an optional fallback value.

```css
.fallback{
    --color-text: white;
    background-color: var(--undeclared-property, black);
    color: var(--underclared-again, var(--color-text, yellow));
}
```

## Scope:
The scope of a custom property is determined by the selector. This scope
includes the selector the custom property was declared for as well as any
descendants of that selector.

## The root selector:
`:root` selector is basically the same as the `html` selector but has higher
specificity.

By declaring our custom property on the `:root` selector we can access
it on any other valid selector within our CSS file.

## Media Queries:
Make sure to set fallback custom properties on the `:root` in case the user
does not have any preference set on their OS. We can use the `prefers-color-scheme`
to switch to the dark theme. In the below example the light theme is the default.
```css

  --border-btn: 1px solid rgb(36, 36, 36);
  --color-base-bg: rgb(240, 240, 240);
  --color-base-text: rgb(18, 18, 18);
  --color-btn-bg: rgb(220, 220, 220);
  --theme-name: "light";
}

@media (prefers-color-scheme: dark) {
  :root {
    --border-btn: 1px solid rgb(220, 220, 220);
    --color-base-bg: rgb(18, 18, 18);
    --color-base-text: rgb(240, 240, 240);
    --color-btn-bg: rgb(36, 36, 36);
    --theme-name: "dark";
  }
}
```
The `prefers-color-scheme` media query only allows between `dark` and `light`
modes. It doesn't allow the user to change the theme themselves, which might be
important

## Fieldset element:
The fieldset element is a container element that allows us to group related
form inputs into one logical unit.

To create a fieldset use the `<fieldset>` element.

Inside a fieldset you can use `<legend>` to give the fieldset a heading 
or caption
## Grid notes:
if you want to set the implicit grid sizes (for when you add an extra grid)
more than the `grid-template-columns` and the `grid-template-rows` properties
we need to use `grid-auto-rows` or `grid-auto-columns`.

Gap allows to set a gutter b/w the grid rows and grid columns.

When layout isn't a priority we can use flexbox instead of grid.

## Extra Notes:
- To get the root element of the document you can use the documentElement property.
Example:
```js
const rootElement = document.documentElement;
```

