# Posterfill

[Demonstration](http://lewisnyman.github.com/posterfill)

The `<video>` element defines a [single poster attribute.](http://www.whatwg.org/specs/web-apps/current-work/multipage/the-video-element.html#attr-video-poster) This library forks Picturefill to supply responsive poster attributes.


**Note:** Posterfill works best in browsers that support CSS3 media queries. It includes (externally) the [matchMedia polyfill](https://github.com/paulirish/matchMedia.js/) which makes matchMedia work in `media-query`-supporting browsers that don't have `matchMedia`, or at least allows media types to be tested in most any browser. `matchMedia` and the `matchMedia` polyfill are not required for `posterfill` to work, but they are required to support the `media` attributes on `video` `div[data-poster]` elements.

## Markup pattern

Mark up your videos like this. 

```html
	<video controls>
		<source src="foo.ogg" type="video/ogg">
		<source src="foo.mp4" type="video/mp4">
		<div data-poster="small.jpg"></div>
		<div data-poster="medium.jpg"     data-media="(min-width: 400px)"></div>
		<div data-poster="large.jpg"      data-media="(min-width: 800px)"></div>
		<div data-poster="extralarge.jpg" data-media="(min-width: 1000px)"></div>
	</video>
```

Each `div[data-poster]` element’s `data-media` attribute accepts any and all CSS3 media queries—such as `min` or `max` width, or even `min-device-pixel-ratio` for HD (retina) displays. 

## Non Javascript support
If you want the poster to appear when no Javascript is availiable, simply add the poster attribute to the `video` element as you would natively. Unfortunately this will result in double downloads for Javascript users.

### HD Media Queries

Posterfill natively supports HD(Retina) image replacement.  While numerous other solutions exist, posterfill has the added benefit of performance for the user in only getting served one image.

* The `data-media` attribute supports [compound media queries](https://developer.mozilla.org/en-US/docs/CSS/Media_queries), allowing for very specific behaviors to emerge.  For example, a `data-media="(min-width: 400px) and (min-device-pixel-ratio: 2.0)` attribute can be used to serve a higher resolution version of the source instead of a standard definition image. Note you currently also need to add the `-webkit-min-device-pixel-ratio` prefix (e.g. for iOS devices).

```html
	<video controls>
		<source src="foo.ogg" type="video/ogg">
		<source src="foo.mp4" type="video/mp4">
		<div data-poster="small.jpg"></div>
		<div data-poster="small.jpg"         data-media="(min-device-pixel-ratio: 2.0)"></div>
		<div data-poster="medium.jpg"        data-media="(min-width: 400px)"></div>
		<div data-poster="medium_x2.jpg"     data-media="(min-width: 400px) and (min-device-pixel-ratio: 2.0)"></div>
		<div data-poster="large.jpg"         data-media="(min-width: 800px)"></div>
		<div data-poster="large_x2.jpg"      data-media="(min-width: 800px) and (min-device-pixel-ratio: 2.0)"></div>	
		<div data-poster="extralarge.jpg"    data-media="(min-width: 1000px)"></div>
		<div data-poster="extralarge_x2.jpg" data-media="(min-width: 1000px) and (min-device-pixel-ratio: 2.0)"></div>	
	</video>
```

* Note: Supporting this many breakpoints quickly adds size to the DOM and increases implementation and maintenance time, so use this technique sparingly.
