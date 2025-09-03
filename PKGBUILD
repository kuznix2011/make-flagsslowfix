# Maintainer: Your Name <you@example.com>
pkgname=make-flagslowfix
pkgver=0.1
pkgrel=1
pkgdesc="Automatically adjust make -j based on system specs and project size"
arch=('x86_64')
url="https://github.com/yourusername/make-flagslowfix"
license=('GPL-3.0-or-later')
depends=('coreutils')
source=()

build() {
    make
}

package() {
    install -Dm755 build/make-flagslowfix "$pkgdir"/usr/bin/make-flagslowfix
}
