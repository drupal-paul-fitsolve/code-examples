/* Load this script using conditional IE comments if you need to support IE 7 and IE 6. */

window.onload = function() {
	function addIcon(el, entity) {
		var html = el.innerHTML;
		el.innerHTML = '<span style="font-family: \'SR-FR-Icons\'">' + entity + '</span>' + html;
	}
	var icons = {
			'fricon-icons_tips_1-50' : '&#xe000;',
			'fricon-icons_tips_2-51' : '&#xe001;',
			'fricon-icons_tips_3-52' : '&#xe002;',
			'fricon-icons_tips_4-53' : '&#xe003;',
			'fricon-icons_tips_5-54' : '&#xe004;',
			'fricon-icons_tips_6-55' : '&#xe005;',
			'fricon-icons_tips_7-56' : '&#xe006;',
			'fricon-icons_tips_8-57' : '&#xe007;',
			'fricon-icons_tips_9-58' : '&#xe008;',
			'fricon-icons_tips_10-59' : '&#xe009;',
			'fricon-icons_tips_11-60' : '&#xe00a;',
			'fricon-icons_tips_12-61' : '&#xe00b;',
			'fricon-icons_tips_13-62' : '&#xe00c;',
			'fricon-icons_tips_14-63' : '&#xe00d;',
			'fricon-icons_tips_15-64' : '&#xe00f;',
			'fricon-icons_tips_16-65' : '&#xe010;',
			'fricon-icons_tips_17-66' : '&#xe011;',
			'fricon-icons_tips_18-67' : '&#xe012;',
			'fricon-icons_tips_19-68' : '&#xe013;',
			'fricon-icons_tips_20-69' : '&#xe014;'
		},
		els = document.getElementsByTagName('*'),
		i, attr, c, el;
	for (i = 0; ; i += 1) {
		el = els[i];
		if(!el) {
			break;
		}
		attr = el.getAttribute('data-icon');
		if (attr) {
			addIcon(el, attr);
		}
		c = el.className;
		c = c.match(/fricon-[^\s'"]+/);
		if (c && icons[c[0]]) {
			addIcon(el, icons[c[0]]);
		}
	}
};