-- phpMyAdmin SQL Dump
-- version 4.6.6
-- https://www.phpmyadmin.net/
--
-- Gép: localhost
-- Létrehozás ideje: 2017. Jún 13. 12:56
-- Kiszolgáló verziója: 5.5.54-0+deb8u1
-- PHP verzió: 7.0.15-1~dotdeb+8.1

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Adatbázis: `hallgatok`
--

-- --------------------------------------------------------

--
-- Tábla szerkezet ehhez a táblához `felhasznalok`
--

CREATE TABLE `felhasznalok` (
  `id` int(11) NOT NULL COMMENT 'Felhasználó egyedi azonosítója',
  `nev` varchar(64) COLLATE utf8_hungarian_ci NOT NULL COMMENT 'Felhasználó neve'
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_hungarian_ci COMMENT='Felhasználói adatok';

--
-- A tábla adatainak kiíratása `felhasznalok`
--

INSERT INTO `felhasznalok` (`id`, `nev`) VALUES
(1, 'Kerekes Károly'),
(2, 'Görkoris Gizi'),
(3, 'Futó Feri');

-- --------------------------------------------------------

--
-- Tábla szerkezet ehhez a táblához `tevekenysegek`
--

CREATE TABLE `tevekenysegek` (
  `id` int(11) NOT NULL COMMENT 'Tevékenység egyedi azonosítója',
  `felhasznalo_id` int(11) NOT NULL COMMENT 'Felhasználó azonosítója',
  `tevekenyseg` int(11) NOT NULL COMMENT '0 = futás, 1 = bringázás, 2 = görkorcsolyázás',
  `tavolsag` float NOT NULL COMMENT 'Megtett távolság km-ben',
  `ev` int(11) NOT NULL COMMENT 'Év',
  `honap` int(11) NOT NULL COMMENT 'Hónap',
  `nap` int(11) NOT NULL COMMENT 'Nap'
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_hungarian_ci COMMENT='Sporttevékenységek nyilvántartása';

--
-- A tábla adatainak kiíratása `tevekenysegek`
--

INSERT INTO `tevekenysegek` (`id`, `felhasznalo_id`, `tevekenyseg`, `tavolsag`, `ev`, `honap`, `nap`) VALUES
(1, 1, 1, 70.5, 2017, 5, 23),
(2, 1, 1, 68.9, 2017, 6, 3),
(3, 1, 1, 49, 2017, 6, 9),
(4, 2, 2, 15, 2017, 5, 11),
(5, 2, 2, 17, 2017, 5, 21),
(6, 3, 0, 5.5, 2017, 6, 6);

--
-- Indexek a kiírt táblákhoz
--

--
-- A tábla indexei `felhasznalok`
--
ALTER TABLE `felhasznalok`
  ADD PRIMARY KEY (`id`);

--
-- A tábla indexei `tevekenysegek`
--
ALTER TABLE `tevekenysegek`
  ADD PRIMARY KEY (`id`);

--
-- A kiírt táblák AUTO_INCREMENT értéke
--

--
-- AUTO_INCREMENT a táblához `felhasznalok`
--
ALTER TABLE `felhasznalok`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT COMMENT 'Felhasználó egyedi azonosítója', AUTO_INCREMENT=4;
--
-- AUTO_INCREMENT a táblához `tevekenysegek`
--
ALTER TABLE `tevekenysegek`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT COMMENT 'Tevékenység egyedi azonosítója', AUTO_INCREMENT=7;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
