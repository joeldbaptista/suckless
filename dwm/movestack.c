/*
 *  `movestack`
 *
 *  Description
 *
 *  This plugin allows you to move clients around in the stack and swap them with the master.
 *  It emulates the behavior off mod+shift+j and mod+shift+k in Xmonad. movestack(+1) will swap the client with the current focus with the next client.
 *  movestack(-1) will swap the client with the current focus with the previous client.
 *
 * */
void
movestack(const Arg *arg)
{
	Client *c = NULL, *p = NULL, *pc = NULL, *i;

	if (arg->i > 0) {
		/* find the client after selmon->sel */
		for (c=selmon->sel->next; c && (!ISVISIBLE(c) || c->isfloating); c=c->next)
			;
		if (!c)
			for(c=selmon->clients; c && (!ISVISIBLE(c) || c->isfloating); c=c->next)
				;

	}
	else {
		/* find the client before selmon->sel */
		for (i=selmon->clients; i != selmon->sel; i=i->next)
			if (ISVISIBLE(i) && !i->isfloating)
				c = i;
		if (!c)
			for (; i; i = i->next)
				if (ISVISIBLE(i) && !i->isfloating)
					c = i;
	}
	/* find the client before selmon->sel and c */
	for (i=selmon->clients; i && (!p || !pc); i=i->next) {
		if (i->next == selmon->sel)
			p = i;
		if (i->next == c)
			pc = i;
	}

	/* swap c and selmon->sel selmon->clients in the selmon->clients list */
	if (c && c != selmon->sel) {
		Client *temp = selmon->sel->next==c?selmon->sel:selmon->sel->next;
		selmon->sel->next = c->next==selmon->sel?c:c->next;
		c->next = temp;

		if (p && p != c)
			p->next = c;
		if (pc && pc != selmon->sel)
			pc->next = selmon->sel;

		if (selmon->sel == selmon->clients)
			selmon->clients = c;
		else if (c == selmon->clients)
			selmon->clients = selmon->sel;

		arrange(selmon);
	}
}

