/* Load this script using conditional IE comments if you need to support IE 7 and IE 6. */

window.onload = function() {
	function addIcon(el, entity) {
		var html = el.innerHTML;
		el.innerHTML = '<span style="font-family: \'fr-icons\'">' + entity + '</span>' + html;
	}
	var icons = {
			'icon-icons_ideas_47' : '&#xe000;',
			'icon-icons_ideas_46' : '&#xe001;',
			'icon-icons_ideas_45' : '&#xe002;',
			'icon-icons_ideas_44' : '&#xe003;',
			'icon-icons_ideas_43' : '&#xe004;',
			'icon-icons_ideas_42' : '&#xe005;',
			'icon-icons_ideas_41' : '&#xe006;',
			'icon-icons_ideas_40' : '&#xe007;',
			'icon-icons_ideas_39' : '&#xe008;',
			'icon-icons_ideas_38' : '&#xe009;',
			'icon-icons_ideas_37' : '&#xe00a;',
			'icon-icons_ideas_36' : '&#xe00b;',
			'icon-icons_ideas_35' : '&#xe00c;',
			'icon-icons_ideas_34' : '&#xe00d;',
			'icon-icons_ideas_33' : '&#xe00e;',
			'icon-icons_ideas_32' : '&#xe00f;',
			'icon-icons_ideas_31' : '&#xe010;',
			'icon-icons_ideas_30' : '&#xe011;',
			'icon-icons_ideas_29' : '&#xe012;',
			'icon-icons_ideas_28' : '&#xe013;',
			'icon-icons_ideas_27' : '&#xe014;',
			'icon-icons_ideas_26' : '&#xe015;',
			'icon-icons_ideas_25' : '&#xe016;',
			'icon-icons_ideas_24' : '&#xe017;',
			'icon-icons_ideas_23' : '&#xe018;',
			'icon-icons_ideas_22' : '&#xe019;',
			'icon-icons_ideas_21' : '&#xe01a;',
			'icon-icons_ideas_20' : '&#xe01b;',
			'icon-icons_ideas_19' : '&#xe01c;',
			'icon-icons_ideas_18' : '&#xe01d;',
			'icon-icons_ideas_17' : '&#xe01e;',
			'icon-icons_ideas_16' : '&#xe01f;',
			'icon-icons_ideas_15' : '&#xe020;',
			'icon-icons_ideas_14' : '&#xe021;',
			'icon-icons_ideas_13' : '&#xe022;',
			'icon-icons_ideas_12' : '&#xe023;',
			'icon-icons_ideas_11' : '&#xe024;',
			'icon-icons_ideas_10' : '&#xe025;',
			'icon-icons_ideas_9' : '&#xe026;',
			'icon-icons_ideas_8' : '&#xe027;',
			'icon-icons_ideas_7' : '&#xe028;',
			'icon-icons_ideas_6' : '&#xe029;',
			'icon-icons_ideas_5' : '&#xe02a;',
			'icon-icons_ideas_4' : '&#xe02b;',
			'icon-icons_ideas_3' : '&#xe02c;',
			'icon-icons_ideas_2' : '&#xe02d;',
			'icon-icons_ideas_1' : '&#xe02e;',
			'icon-icons_ideas_48' : '&#xe02f;'
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
		c = c.match(/icon-[^\s'"]+/);
		if (c && icons[c[0]]) {
			addIcon(el, icons[c[0]]);
		}
	}
};